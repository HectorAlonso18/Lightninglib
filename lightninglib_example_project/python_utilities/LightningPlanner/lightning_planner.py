'''
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
'''

from multiprocessing.connection import wait
from operator import truediv
from pydoc import cli
from re import I
import turtle
import os
import math
import time 


cancha = turtle


def close_field(): 
    cancha.bye()

def create_field_waypoints_folder(path):
    if not os.path.exists(path):
        os.mkdir(path)
        print("\nThe Lightning-waypoints folder has been created")
        print(",Here, the waypoints will be saved.")
    
    else: 
        print("\nLightning-waypoints folder already exist. Here the waypoints will be saved.")


def check_waypoint_index(waypoints_path):
    index = 1
    waypoints_exists = True

    while waypoints_exists:
        pic_name = "waypoints_" + str(index) + ".txt"
        pic_path = os.path.join(waypoints_path, pic_name)

        if os.path.exists(pic_path):
            index += 1
        else:
            waypoints_exists = False

    return index

def print_instructions():
    print("¡Welcome to LightningPlanner!")
    print("\nInstructions: ")
    print("\n-> Left-click on the spot where you want to move your robot.")
    print("\n-> Right-click to print all the coordinates you have generated.")
    print("\n-> Press the 's' key to save the coordinates to a txt file in Lightning-waypoints.")
    print("\n-> Press the 'r' key to reset the coordinates and start over.")
    print("\n-> Press the 'q' key to exit the program.\n")

project_path = (os.path.dirname(os.path.abspath(__file__)))
assets_path  = os.path.join(project_path, "Planner_assets")
waypoints_path = os.path.join(project_path,"Lightning-waypoints")

field_path = "" 
bot_path= ""

patron_texto = """
******************************************************************
*    _     _       _     _         _                   .$$$$$"   *
*   | |   (_) __ _| |__ | |_ _ __ (_)_ __   __ _      z$$$$$"    *
*   | |   | |/ _` | '_ \| __| '_ \| | '_ \ / _` |    z$$$$P      *
*   | |___| | (_| | | | | |_| | | | | | | | (_| |   d$$$$$$$$$"  *
*   |_____|_|\__, |_| |_|\__|_| |_|_|_| |_|\__, |  *******$$$"   *
*            |___/                         |___/        .$$$"    *
*                                                      .$$"      *
******************************************************************
"""


print(patron_texto)

time.sleep(.5)
print_instructions()
time.sleep(.5)
create_field_waypoints_folder(waypoints_path)
index = check_waypoint_index(waypoints_path)


print("\nSet UP\n")

competition = input ("What competition [VRC] or [VEXU]?: ")

if(not(competition=="VRC" or competition=="VEXU")):
    print("\n No a valid competition, VRC selected") 
    competition= "VRC"

match_or_skills = input("[MATCH] or [SKILLS]?: ")
if(not(match_or_skills=="MATCH" or match_or_skills=="SKILLS")):
    print("\n No a valid competition, MATCH selected") 
    match_or_skills= "MATCH"


size_turtle=0; 

if(competition=="VRC"):
    size_turtle=508
    if(match_or_skills=="SKILLS"):
        bot_path= os.path.join(assets_path,"red_bot.gif")
        field_path =os.path.join(assets_path,"VRC_SKILLS.gif")

    else: 
        bot_color  = input ("Select an alliance [RED] or [BLUE]: ")

        if(not(bot_color=="RED" or bot_color=="BLUE")):
            bot_color="RED"
            print("\n No a valid alliance, RED alliance setted") 
        
        if(bot_color=="RED"):
            bot_path= os.path.join(assets_path,"red_bot.gif")
            field_path =os.path.join(assets_path,"VRC_RED.gif")

        else: 
            bot_path= os.path.join(assets_path,"blue_bot.gif")
            field_path =os.path.join(assets_path,"VRC_BLUE.gif")



if(competition=="VEXU"):
    size_turtle = 557
    if(match_or_skills=="SKILLS"):
        bot_path= os.path.join(assets_path,"red_bot.gif")
        field_path =os.path.join(assets_path,"VEX_U_SKILLS.gif")
        

    else: 
        bot_color  = input ("Select an alliance [RED] or [BLUE]: ")

        if(not(bot_color=="RED" or bot_color=="BLUE")):
            bot_color="RED"
            print("\n No a valid alliance, RED alliance setted") 
        
        if(bot_color=="RED"):
            bot_path= os.path.join(assets_path,"red_bot.gif")
            field_path =os.path.join(assets_path,"VEX_U_RED.gif")
        
        else: 
            bot_path= os.path.join(assets_path,"blue_bot.gif")
            field_path =os.path.join(assets_path,"VEX_U_BLUE.gif")
           


cancha = turtle.Screen() # Define la cancha como una pantalla que se va a mostrar
cancha.title("Welcome to LightningPlanner")
cancha.setup(width=size_turtle, height=size_turtle)  # Define las medidas de la cancha
cancha.bgpic(field_path)


length_field_inches= 144

pixels_inches_scale = length_field_inches/size_turtle


#Seleccionar (0,0)
coordenadas = ()
xcero = 0
ycero = 0
x = 0
y = 0
lock = 0
xs = []
ys = []

turtle.addshape(bot_path)

def coordenadas(x, y):
    global clicks, xcero, ycero, lock, xs, ys
    if lock == 0:
        coordenadas = (x, y)
        xcero = coordenadas[0]
        ycero = coordenadas[1]
        turtle.pensize(0)
        turtle.goto(xcero, ycero)
        turtle.pensize(5)
      
        print("Origin: x:", 0,"(inches) ", "y: ", 0,"(inches)")
        lock = 1
        turtle.shape(bot_path)
     

    elif lock == 1:
        m= turtle.Turtle()
        m.penup
        m.goto(x,y)
        m.pendown()
        m.shape(bot_path)

        x_respecto = (x - xcero) * pixels_inches_scale
        y_respecto = (y - ycero) * pixels_inches_scale

        print("x: %.2f" % x_respecto,"(inches) ", "y: %.2f" % y_respecto,"(inches)")
        turtle.goto(x, y)
        xs.append(x_respecto)
        ys.append(y_respecto)


def reset():  
    #Reiniciamos variables para las coordenadas
    global xcero,ycero,xs,ys,lock
    xcero =0
    ycero=0
    xs=[]
    ys=[]
    lock=0

    cancha.clear()
    cancha.bgpic(field_path)
    cancha.addshape(bot_path)

    #Reseteamos clicks
    turtle.onscreenclick(coordenadas, 1)
    turtle.onscreenclick(print_cords, 3)
    
    #Reseteamos eventos de teclas
    print("RESET")
    cancha.onkey(close_field, "q")
    cancha.listen()

    cancha.onkey(save_cords,"s")
    cancha.listen()

    cancha.onkey(reset,"r")
    cancha.listen()



def print_cords(x, y):
    print("X: ", xs)
    print("Y: ", ys)

def save_cords():
    global waypoints_path, index 
    waypoint_file_name = "waypoints_" +str(index) + ".txt"
    waypoint_path = os.path.join(waypoints_path, waypoint_file_name)

    with open(waypoint_path, "w") as file:
        file.write("X: {" + ", ".join(map(str, xs)) + "}\n")
        file.write("Y: {" + ", ".join(map(str, ys)) + "}\n") 

    index+=1   

#click izquierdo
turtle.onscreenclick(coordenadas, 1) 
#click derecho
turtle.onscreenclick(print_cords, 3)


cancha.onkey(close_field, "q")
cancha.listen()

cancha.onkey(save_cords,"s")
cancha.listen()

cancha.onkey(reset,"r")
cancha.listen()


turtle.mainloop()
