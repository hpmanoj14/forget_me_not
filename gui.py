# import tkinter as tk
from PIL import ImageTk, Image
# import cv2
# window = tk.Tk()
# window.title("Join")
# window.geometry("500x500")
# window.configure(background='grey')
#
# path = "keys.jpg"
# image = Image.open(path)
# resize_image = image.resize((100, 100))
# #Creates a Tkinter-compatible photo image, which can be used everywhere Tkinter expects an image object.
# img = ImageTk.PhotoImage(resize_image)
# panel = tk.Label(window, image = img)
# panel.place(x=0,y=0)
#
# #The Pack geometry manager packs widgets in rows or columns.
# panel.pack(side = "bottom", fill = "both", expand = "yes")
#
# #Start the GUI
# window.mainloop()
# #
# # #
# root = tk.Tk()
# canvas = tk.Canvas(root, width = 300, height = 300)
# canvas.pack()
# img = Image.open(path)
# canvas.create_image(20,20, image=img, anchor='ne')
# mainloop()

import tkinter as tk

window = tk.Tk()
window.geometry("500x500")
keys = Image.open("keys.png")
keys = keys.resize((50,50), Image.ANTIALIAS)
photoKeys = ImageTk.PhotoImage(keys)
labelKeys = tk.Label(image = photoKeys)
labelKeys.image = keys
labelKeys.place(x=50,y=110)
#img = tk.PhotoImage(file="keys.png")
#resize_image = img.zoom(50, 50)
# lab = tk.Label(root, text="Hello")
# lab.grid()
# lab["compound"] = tk.LEFT
# lab["image"] = photoImg

window.mainloop()