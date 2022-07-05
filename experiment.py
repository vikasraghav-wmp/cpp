import boto3
import json
import os
import sys

packageJson = open("package.json", "r")  #Require Package.json for fetching Latest Version
buildSpecJson=open("buildspec.json","r")
client = boto3.client('ecs')
js = json.load(packageJson)
env=json.load(buildSpecJson)
# task_definition=js['name']
cluster=env['cluster']
service=env['service']
taskDefinition=env['taskDefinition']
print('taskDefinition',taskDefinition)
print('service',service)
print('cluster',cluster)

#####Fetch Task definition##################
def fetchTaskDef():
    global response
    response = client.describe_task_definition(
            taskDefinition=taskDefinition,
            include=[
                'TAGS',
            ]
        )
    print("Fetched Task Definition from AWS")
    deleteValuesFromTaskDef()

######Remove Unwanted Parameters from Task definition#####
def deleteValuesFromTaskDef():
    global initialTaskDefinition
    initialTaskDefinition=response['taskDefinition']
    initialTaskDefinition.pop('taskDefinitionArn')
    initialTaskDefinition.pop('revision')
    initialTaskDefinition.pop('status')
    initialTaskDefinition.pop('compatibilities')
    initialTaskDefinition.pop('requiresAttributes')
    initialTaskDefinition.pop('registeredAt')
    initialTaskDefinition.pop('registeredBy')
    print("Deleted Unrequired Parameters")
    modifyContainerImage()

###### Fetch the Latest Image From Package Json ###################
def modifyContainerImage():
    ContainerImage=env['ContainerImage']
    containerDefinitions= initialTaskDefinition['containerDefinitions'][0] # Extracted containerDefinitions array
    packageName=js['name']
    packageVersion=js['version']
    ContainerImage+=packageName+":"+packageVersion  #Concatenate Package name and Version with ECR ARN
    print('Image That will be Deployed is',ContainerImage)
    ##### Replacing Existing Image Parameter Value with Latest Image Version #####
    if 'image' in containerDefinitions.keys():
        containerDefinitions['image'] = ContainerImage
        print('Modified Existing Image Value with Latest Package Version',packageVersion)
        deployImageToECS()
    else:
        print('Does Not Find Image Parameter in Task Definition')

#### Register latest Task definition and Deploy to ECS #####
def deployImageToECS() :
    print("Creating Task definition file with Latest Values")
    with open('taskdefinition.json', 'w') as createfile:
        json.dump(initialTaskDefinition, createfile)
    print("Creating latest revision of Task Definition")
    # Create new Task Definition
    os.system('aws ecs register-task-definition --cli-input-json file://taskdefinition.json')
    print("Created Latest Revision of Task Definition")
    # Deploy Latest Revision To ECS
    cmd = "aws ecs update-service --cluster " +cluster+ " --service " +service+ " --task-definition " +taskDefinition
    os.system(cmd)
    print("Deployed Latest Build To ECS")
    ### Remove taskdefinition.json File ####
    os.system('rm taskdefinition.json')

###### Call the Functions#########
fetchTaskDef()
