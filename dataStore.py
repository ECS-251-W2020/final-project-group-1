class dataStore:
    def __init__(self, fileAccess, inodes, compTime):
        self.fileAccess = fileAccess
        self.inodes = inodes
        self.compTime = compTime

        #Test Dictionary for file pointers
        self.fileDict = {}

        for i in range(len(self.inodes)):
            self.fileDict[self.inodes[i]] = self.fileAccess[i]
        

    def showData(self):
        print("fileAccess", self.fileAccess)
        print("inodes", self.inodes)
        print("computation time", self.compTime)

    def fileData(self):
        print(self.fileDict)

