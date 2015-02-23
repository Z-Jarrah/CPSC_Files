import sys
import string
#Building lexer to parse tokens
#Output lexeme and token type
# Read in keyword, seperator, operator from files

def LoadFile(fileName):
    myList = []
    with open(fileName, 'r') as inputfh:
        for line in inputfh:
            line = line.rstrip()
            myList.append(line)
        return myList
        
def ParseTokens(source):
    tokenList = []
    for line in source:
        for letter in line:
            print(letter)

#print(len(keyword))
#for i in range(0,len(keyword)):
#        print(keyword[i])


def FindKeyword(token, fList):
    for i in range(0, len(fList)):
        if token == fList[i]:
            print("token match: ")
            print(fList[i])
 
#inputfilename = sys.argv[1]
#with open(inputfilename, 'r') as inputfh:
#    for line in inputfh:
#            for letter in line:

def main():
    keywordList = LoadFile("keywords.txt")
    seperatorList = LoadFile("seperators.txt")
    operatorList = LoadFile("operators.txt")
    sourceCode = LoadFile("source.txt")
    ParseTokens(sourceCode)
            
        
if __name__ == "__main__":
  main( )


