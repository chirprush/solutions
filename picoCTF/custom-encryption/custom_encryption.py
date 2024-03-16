from random import randint
import sys

def encrypt(plaintext, key):
    cipher = []
    for char in plaintext:
        cipher.append(((ord(char) * key*311)))
    return cipher

def is_prime(p):
    v = 0
    for i in range(2, p + 1):
        if p % i == 0:
            v = v + 1
    if v > 1:
        return False
    else:
        return True

def dynamic_xor_encrypt(plaintext, text_key):
    cipher_text = ""
    key_length = len(text_key)
    for i, char in enumerate(plaintext[::-1]):
        key_char = text_key[i % key_length]
        encrypted_char = chr(ord(char) ^ ord(key_char))
        cipher_text += encrypted_char
    return cipher_text

def test(plain_text, text_key):
    p = 97
    g = 31
    if not is_prime(p) and not is_prime(g):
        print("Enter prime numbers")
        return
    a = randint(p-10, p)
    b = randint(g-10, g)
    print(f"a = {a}")
    print(f"b = {b}")
    u = pow(g, a, p)
    v = pow(g, b, p)
    key = pow(v, a, p)
    b_key = pow(u, b, p)
    shared_key = None
    if key == b_key:
        shared_key = key
    else:
        print("Invalid key")
        return
    print("Key:",shared_key)
    semi_cipher = dynamic_xor_encrypt(plain_text, text_key)
    print("Semi-Cipher (str -> [int]):", [ord(i) for i in semi_cipher])
    cipher = encrypt(semi_cipher, shared_key)
    print(f'cipher = {cipher}')

if __name__ == "__main__":
    message = "this_is_a_test_message"
    test(message, "text_key")
