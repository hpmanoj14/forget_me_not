import os
import tkinter as tk
from tkinter.constants import GROOVE, RAISED
from tkinter import *
import time


items = ["Phone", "Wallet", "Glasses", "Keys"]


window = tk.Tk()
window.geometry("400x400")
greeting = tk.Label(
    text="List of Items",    
    width=40,
    font=("Times", 30, "bold"),
    fg="red",
    height=3
)

text1 = tk.Label(window, 
    text="1."+ "    ",
    width=40,
    font=("Ariel", 15),
    fg="blue",
    height=2)

text2 = tk.Label(window, 
    text="2."+ "    ",
    width=40,
    font=("Ariel", 15),
    fg="blue",
    height=2)

text3 = tk.Label(window, 
    text="3."+ "    ",
    width=40,
    font=("Ariel", 15),
    fg="blue",
    height=2)

text4 = tk.Label(window, 
    text="4."+ "    ",
    width=40,
    font=("Ariel", 15),
    fg="blue",
    height=2)

text1.place(x=0,y=110)
text2.place(x=0,y=125)
text3.place(x=0,y=140)
text4.place(x=0,y=155)

greeting.pack()
text1.pack()
text2.pack()
text3.pack()
text4.pack()

time.sleep( 1 )
text1[ "text" ]="1."+ "    " + items[0]
window.update()

time.sleep( 1 )
text2[ "text" ]="2."+ "    " + items[1]
window.update()

time.sleep( 1 )
text3[ "text" ]="3."+ "  " + items[2]
window.update()

time.sleep( 1 )
text4[ "text" ]="4."+ "    " + items[3]
window.update()


window.mainloop()

if len(stuff) > 0:
    text1["text"] = "1." + "    " + stuff[-1]
    window1.update()