import sys
import string
#Building lexer to parse tokens
#Output lexeme and token type
# Read in keyword, seperator, operator from files

def LoadFile(fileName):
    myList = []
    with open(fileName, 'r') as inputfh:
        for line in inputfh:
            line = line.strip()
            myList.append(line)
        return myList
        
def ParseTokens(sourceFile, tokenList):
    tokenList = []
    token = ""
    with open(sourceFile, 'r') as inputfh:
        for line in inputfh:
            for letter in line:
                if letter != ' ':
                    token += letter
                elif token == '':
                    token = ""
                else:
                    token = token.strip()
                    tokenList.append(token)
                    token = ""
        return tokenList

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
    lexeme = []
    keywordList = LoadFile("keywords.txt")
    seperatorList = LoadFile("seperators.txt")
    operatorList = LoadFile("operators.txt")
    lexeme = ParseTokens("source.txt", lexeme)
    print(lexeme)
            
        
if __name__ == "__main__":
  main( )


