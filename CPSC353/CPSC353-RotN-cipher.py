# A simple implementation of the ROT-N cipher
# Encrypts by shifting letter of the alphabet by a given number
# Returns a ciphered message based off the provided shift
# How to run: $python CPSC353-RotN-cipher.py <shift> <message>
# Compatible with Python3

import sys

def rotN(message, shift):
    rot_n_message = ""
    for line in message:
        for letter in line:
            if letter != ' ':
                token = encrypt(letter, shift)
                rot_n_message += token
            else:
                rot_n_message += ' '
    rot_n_message += '\n'
    return rot_n_message


def encrypt(letter, s):
    s = int(s)
    numeric_rot = ord(letter.lower()) + s
    # Letter must roll back to 'a'
    if(numeric_rot > ord('z')):
        numeric_rot = numeric_rot % 122 + 96
    return chr(numeric_rot)


def main():
    letter_shift = sys.argv[1]
    plain_text = sys.argv[2]
    message = rotN(plain_text, letter_shift)
    print(message)

if __name__ == "__main__":
    main()