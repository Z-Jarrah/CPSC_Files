# A simple implementation of the ROT-N decipher
# A brute force decryption program
# Returns all possible combinations of the ROT-N cipher
# How to run: $python CPSC353-RotN-decipher.py <message>
# Compatible with Python3

import sys

def rotN(message, shift):
    rot_n_message = ""
    for line in message:
        for letter in line:
            if letter != ' ':
                token = decrypt(letter, shift)
                rot_n_message += token
            else:
                rot_n_message += ' '
    rot_n_message += '\n'
    return rot_n_message


def decrypt(letter, s):
    s = int(s)
    # Same as the encryption but subtracting away the shift
    numeric_rot = ord(letter.lower()) - s 
    # Letter must roll back to 'a'
    if(numeric_rot < ord('a')):
        numeric_rot = numeric_rot % 122 + 96
    return chr(numeric_rot)


def main():
    plain_text = sys.argv[1]
    for i in range(1,26):
        print(i)
        message = rotN(plain_text, i)
        print(message)

if __name__ == "__main__":
    main()