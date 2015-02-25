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
        
def ParseTokens(sourceFile):
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

def TokenIdent(listOfTokens, keywords, separators, operators):
    lexemes = listOfTokens
    tokenId = []
    identified = False
    for i in range(0,len(lexemes)):
        for j in range(0, len(keywords)):
            if lexemes[i] == keywords[j]:
                tokenId.append("keyword")
                identified = True
        for k in range(0, len(separators)): 
            if lexemes[i] == separators[k]:
                tokenId.append("seperator")
                identified = True
        for l in range(0, len(operators)):
            if lexemes[i] == operators[l]:
                tokenId.append("operator")
                identified = True
        if(identified == False):
            tokenId.append(" ")     
    return tokenId 
        
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
    separatorList = LoadFile("separators.txt")
    operatorList = LoadFile("operators.txt")
    lexeme = ParseTokens("source.txt")
    
    idOfTokens = TokenIdent(lexeme, keywordList, separatorList, operatorList)
    
    print(len(idOfTokens))
    print(idOfTokens)
    print(len(lexeme))
    print(lexeme)
         
if __name__ == "__main__":
  main( )


