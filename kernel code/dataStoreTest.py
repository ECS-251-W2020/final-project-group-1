from dataStore import dataStore

fileAccess = ["/home/anushabangi/test1.py", "/home/anushabangi/test2.py"]
inodes = ["testnode1", "testnode2"]
computationTime = [19.00, 20.00]

dataObject = dataStore(fileAccess,inodes,computationTime)

print("Printing Object Values ...")
dataObject.showData()

print("Printing file dictionary")
dataObject.fileData()

