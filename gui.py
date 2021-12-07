import tkinter as tk
from PIL import ImageTk, Image
import cv2
window = tk.Tk()
window.title("Join")
window.geometry("500x500")
window.configure(background='grey')

path = "michigan.jpg"

#Creates a Tkinter-compatible photo image, which can be used everywhere Tkinter expects an image object.
img = ImageTk.PhotoImage(Image.open(path))
panel = tk.Label(window, image = img)

#The Pack geometry manager packs widgets in rows or columns.
panel.pack(side = "bottom", fill = "both", expand = "yes")

#Start the GUI
window.mainloop()