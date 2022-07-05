import boto3
import json
import os   

packageJson = open("package.json", "r")  #Require Package.json for fetching Latest Version 
buildSpecJson=open("buildspec.json","r")
client = boto3.client('ecs')
js = json.load(packageJson)
env=json.load(buildSpecJson)
# task_definition=js['name']
cluster=env['cluster']
service1=env['service1']
service2=env['service2']
service3=env['service3']
taskDefinition1=env['taskDefinition1']
taskDefinition2=env['taskDefinition2']
taskDefinition3=env['taskDefinition3']
print('taskDefinition1',taskDefinition1)
print('taskDefinition2',taskDefinition2)
print('taskDefinition3',taskDefinition3)
print('service1',service1)
print('service2',service2)
print('service3',service3)
print('cluster',cluster)

#####Fetch Task definition##################
def fetchTaskDefUaam():
    global response
    response = client.describe_task_definition(
            taskDefinition=taskDefinition1,
            include=[
                'TAGS',
            ]
        )
    print("Fetched Task Definition from AWS")
    deleteValuesFromTaskDefUaam()

def fetchTaskDefFms():
    global response
    response = client.describe_task_definition(
            taskDefinition=taskDefinition2,
            include=[
                'TAGS',
            ]
        )
    print("Fetched Task Definition from AWS")
    deleteValuesFromTaskDefFms()

def fetchTaskDefPms():
    global response
    response = client.describe_task_definition(
            taskDefinition=taskDefinition3,
            include=[
                'TAGS',
            ]
        )
    print("Fetched Task Definition from AWS")
    deleteValuesFromTaskDefPms()

######Remove Unwanted Parameters from Task definition#####
def deleteValuesFromTaskDefUaam():
    global initialTaskDefinition
    initialTaskDefinition=response['taskDefinition1']
    initialTaskDefinition.pop('taskDefinitionArn')
    initialTaskDefinition.pop('revision')
    initialTaskDefinition.pop('status')
    initialTaskDefinition.pop('compatibilities')
    initialTaskDefinition.pop('requiresAttributes')
    initialTaskDefinition.pop('registeredAt')
    initialTaskDefinition.pop('registeredBy')
    print("Deleted Unrequired Parameters")
    modifyContainerImageUaam()

def deleteValuesFromTaskDefFms():
    global initialTaskDefinition
    initialTaskDefinition=response['taskDefinition2']
    initialTaskDefinition.pop('taskDefinitionArn')
    initialTaskDefinition.pop('revision')
    initialTaskDefinition.pop('status')
    initialTaskDefinition.pop('compatibilities')
    initialTaskDefinition.pop('requiresAttributes')
    initialTaskDefinition.pop('registeredAt')
    initialTaskDefinition.pop('registeredBy')
    print("Deleted Unrequired Parameters")
    modifyContainerImageFms()

def deleteValuesFromTaskDefPms():
    global initialTaskDefinition
    initialTaskDefinition=response['taskDefinition3']
    initialTaskDefinition.pop('taskDefinitionArn')
    initialTaskDefinition.pop('revision')
    initialTaskDefinition.pop('status')
    initialTaskDefinition.pop('compatibilities')
    initialTaskDefinition.pop('requiresAttributes')
    initialTaskDefinition.pop('registeredAt')
    initialTaskDefinition.pop('registeredBy')
    print("Deleted Unrequired Parameters")
    modifyContainerImagePms()

###### Fetch the Latest Image From Package Json ###################
def modifyContainerImageUaam():
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
        deployImageToECSUaam()
    else:
        print('Does Not Find Image Parameter in Task Definition')

def modifyContainerImageFms():
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
        deployImageToECSFms()
    else:
        print('Does Not Find Image Parameter in Task Definition')

def modifyContainerImagePms():
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
        deployImageToECSPms()
    else:
        print('Does Not Find Image Parameter in Task Definition')


#### Register latest Task definition and Deploy to ECS #####
def deployImageToECSUaam() : 
    print("Creating Task definition file with Latest Values")
    with open('taskdefinition.json', 'w') as createfile:
        json.dump(initialTaskDefinition, createfile)
    print("Creating latest revision of Task Definition")
    # Create new Task Definition
    os.system('aws ecs register-task-definition --cli-input-json file://taskdefinition.json')
    print("Created Latest Revision of Task Definition")
    # Deploy Latest Revision To ECS
    cmd = "aws ecs update-service --cluster " +cluster+ " --service " +service1+ " --task-definition " +taskDefinition1
    os.system(cmd)
    print("Deployed Latest Build To ECS")
    ### Remove taskdefinition.json File ####
    os.system('rm taskdefinition.json')

def deployImageToECSFms() : 
    print("Creating Task definition file with Latest Values")
    with open('taskdefinition.json', 'w') as createfile:
        json.dump(initialTaskDefinition, createfile)
    print("Creating latest revision of Task Definition")
    # Create new Task Definition
    os.system('aws ecs register-task-definition --cli-input-json file://taskdefinition.json')
    print("Created Latest Revision of Task Definition")
    # Deploy Latest Revision To ECS
    cmd = "aws ecs update-service --cluster " +cluster+ " --service " +service2+ " --task-definition " +taskDefinition2
    os.system(cmd)
    print("Deployed Latest Build To ECS")
    ### Remove taskdefinition.json File ####
    os.system('rm taskdefinition.json')

def deployImageToECSPms() : 
    print("Creating Task definition file with Latest Values")
    with open('taskdefinition.json', 'w') as createfile:
        json.dump(initialTaskDefinition, createfile)
    print("Creating latest revision of Task Definition")
    # Create new Task Definition
    os.system('aws ecs register-task-definition --cli-input-json file://taskdefinition.json')
    print("Created Latest Revision of Task Definition")
    # Deploy Latest Revision To ECS
    cmd = "aws ecs update-service --cluster " +cluster+ " --service " +service3+ " --task-definition " +taskDefinition3
    os.system(cmd)
    print("Deployed Latest Build To ECS")
    ### Remove taskdefinition.json File ####
    os.system('rm taskdefinition.json')



###### Call the Functions#########
fetchTaskDef() 