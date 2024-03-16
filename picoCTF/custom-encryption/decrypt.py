from typing import List

def decrypt(cipher: List[int], key: int) -> str:
    semi_cipher = ""

    for i in cipher:
        semi_cipher += chr(i // (key * 311))

    return semi_cipher

def xor_decrypt(semi_cipher: str, text_key: str) -> str:
    plain_text = ""
    key_length = len(text_key)

    for i, char in enumerate(semi_cipher):
        key_char = text_key[i % key_length]
        # Undo the xor
        plain_text = chr(ord(char) ^ ord(key_char)) + plain_text

    return plain_text

cipher = [61578, 109472, 437888, 6842, 0, 20526, 129998, 526834, 478940, 287364, 0, 567886, 143682, 34210, 465256, 0, 150524, 588412, 6842, 424204, 164208, 184734, 41052, 41052, 116314, 41052, 177892, 348942, 218944, 335258, 177892, 47894, 82104, 116314]
a, b = 90, 26
p = 97
g = 31

key = pow(g, a * b, p)
text_key = "trudeau"

print("Key:", key)

semi_cipher = decrypt(cipher, key)
print("Semi-Cipher (str -> [int]):", [ord(i) for i in semi_cipher])
print("Message:", xor_decrypt(semi_cipher, text_key))
