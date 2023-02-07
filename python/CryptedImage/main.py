from PIL import Image
import numpy as np
import sys

# imageLue = Image.open("input.jpeg")

# #Afficher l'image
# imageLue.show()

sbox = [12, 5, 6, 11, 9, 0, 10, 13, 3, 14, 15, 8, 4, 7, 1, 2]


def round(key, msg):
    return sbox[msg ^ key]


def enc(key, msg):
    tmp = round(key[0], msg)
    res = round(key[1], tmp)
    return res


reverse_box = [sbox.index(n) for n in range(0, 16)]


def back_round(k, c):
    return reverse_box[c] ^ k


def dec(key, ctxt):
    tmp = back_round(key[1], ctxt)
    res = back_round(key[0], tmp)
    return res


def enc_bytes(lettre, key):
    binascii = bin(lettre)
    binascii = int(binascii, 2)
    nib1 = binascii >> 4
    nib2 = binascii & 0x0F
    result = (bin(enc(key, nib1) << 4 ^ enc(key, nib2)))
    return int(result, 2)


def dec_bytes(chiffre, key):
    binascii = bin(chiffre)
    binascii = int(binascii, 2)
    nib1 = binascii >> 4
    nib2 = binascii & 0x0F
    result = int(bin(dec(key, int(nib1)) << 4 ^ dec(key, int(nib2))), 2)
    return int(result)


def get_image(image_path):
    """Get a numpy array of an image so that one can access values[x][y]."""
    image = Image.open(image_path, "r")
    width, height = image.size
    pixel_values = list(image.getdata())
    if image.mode == "RGB":
        channels = 3
    elif image.mode == "L":
        channels = 1
    else:
        print("Unknown mode: %s" % image.mode)
        return None
    pixel_values = np.array(pixel_values).reshape((width, height, channels))
    return pixel_values


image = get_image("input.jpeg")

print(image[0][0])
print(image.shape)
print(len(image), len(image[0]), len(image[0][0]))


def enc_img(img, key):
    for i in range(len(image)):
        for j in range(len(image[0])):
            for o in range(len(image[0][0])):
                img[i][j][o] = enc_bytes(img[i][j][o], key)

enc_img(image,sbox)

img = Image.open("input.jpeg")
img.show()
def change_pixel(img,pixel_list):
	for i in range(len(pixel_list)):
		for j in range(len(pixel_list[0])):
			px = (pixel_list[i][j][0],pixel_list[i][j][1],pixel_list[i][j][2])
			img.putpixel((i,j),px)

change_pixel(img,image)

x = img.size[0]
y = img.size[1]
# # #Afficher l'image
#img.show()

img_enc = Image.new('RGB', (x, y), color = 'black')
change_pixel(img_enc,image)
#change_pixel(img,image)
img_enc.save('output_enc.png')
img_enc.show()