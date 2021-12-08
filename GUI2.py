# from PIL import ImageTk, Image, ImageDraw, ImageFont
# import time
#
# keys = Image.open("keys.jpg")
# draw = ImageDraw.Draw(keys)
# keys.show()
# time.sleep( 1 )
# keys.close()

# import tkinter
# from tkinter import *
# from PIL import Image, ImageTk
#
# root = Tk()
#
# # Position text in frame
# Label(root, text = 'Position image on button', font =("Ariel", 15)).pack(side = TOP, padx = 10, pady = 10)
#
# # Create a photoimage object of the image in the path
# #photo = PhotoImage(file = "keys.jpg")
# keys = Image.open("keys.png")
# keys = keys.resize((50,50), Image.ANTIALIAS)
# photo = PhotoImage(keys)
# #print("type", type(photo))
# # Resize image to fit on button
# photoimage = photo.subsample(1, 2)
# #print("type2", type(photoimage))
#
# # Position image on button
# Button(root, image = photo).pack(side = BOTTOM, pady = 2)
# mainloop()

import numpy as np
import matplotlib.pyplot as plt
from PIL import Image

ImageAddress = 'keys.jpg'
ImageItself = Image.open(ImageAddress)
ImageNumpyFormat = np.asarray(ImageItself)
plt.imshow(ImageNumpyFormat)
plt.draw()
plt.pause(5) # pause how many seconds
plt.close()