import sys
import os
import dataStore

def main():

    filename = sys.argv[1]
    if not os.path.isfile(filename):
       print("File path does not exist. Exiting...")
       sys.exit()
    #linecol = []
    ## TODO: find out how strace gets first block being accessed and number of blocks. change fileAccesses list accordingly to store this info
    fileAccesses = []
    inodes = []
    addresses = []
    computationTimes = []
    with open(filename) as fp:
        for line in fp:
            if((line.split(" ")[1][:4]=='stat') | (line.split(" ")[1][:5]=='fstat') | (line.split(" ")[1][:5]=='lstat')):
                fileAccesses.append(line)
            #linecol.append(line.split(" "))
    fp.close()
    #print(fileAccesses[0])
    prevTime = float(fileAccesses[0].split(" ")[0])
    index = 0
    for fa in fileAccesses:
        if(fa.split(" ")[4]=='-1'):
            continue
        else:
            startTime = float(fa.split(" ")[0])
            ct = format((startTime - prevTime),'.6f')
            #print(ct)
            computationTimes.append(ct)
            prevTime = startTime
            inodePlusAddr = fa.split("{")
            inodes.append(inodePlusAddr[1].split("}")[0])
            addresses.append(inodePlusAddr[1].split("}")[1][6:-6])
    postprocFile = open("postProc.txt","w+")
    for index in range(len(inodes)):
        if(index!=(len(inodes)-1)):
            postprocFile.write(inodes[index]+" "+computationTimes[index+1]+" "+addresses[index]+"\r\n")
        else:
            postprocFile.write(inodes[index]+" "+addresses[index]+"\r\n")

    #Create dataStore object
    #dataObject = dataStore(fileAccesses, inodes, adddresses, computationTimes)
if __name__=='__main__':
    main()
