/*
 * Luka Gobovic - 20215231
 * Assignment 4
 * ShapesGood implementation file
 * December 5th, 2022
 * 
 * This hierarchy is part of a structure supposedly to be used with a drawing program.  For
 * this assignment you are concerned with the structure and not about actually drawing
 * anything.  For the purpose of having a few attributes around, a Shape will have a size
 * and colours will be supplied when the Shape is to be drawn.  A Shape can have an outline
 * colour, a fill colour and could hold text.
 *
 * This is an example of a poor inheritance structure.  It has a single base class, Shape,
 * and all other classes extend Shape.  It is an example of an exponential hierarchy, since
 * all classes extend just the one base class and very little is shared.  As you will see
 * from the ugly code in TestBadShapes.cpp, this structure does not support polymorphism.
 *
 * For CISC/CMPE 320, Assignment 5
 */

#ifndef SHAPESGOOD_H
#define SHAPESGOOD_H

#include <string>

using namespace std;

//Base shape class that is used by other classes
class Shape
{
public:
  Shape(int length, int width);  
  virtual ~Shape(); // Destructor, virtual since objects are deleted, to avoid mem leaks 
  virtual void draw(); //Draw function, virtual since it declared here (base class) and is re-defined in the derived shape classes
  int getLength() const; //Length Accessor, constant to avoid modification 
  int getWidth() const; //Width Accessor, constant to avoid modification

private:
  int length, width;  //Shape parameters
};

//Fillable class for shapes that are filled with a colour
class Fillable
{
public:
  Fillable (string fillColour); //Constructor for fillable, containing one string parameter for the fill colour
  virtual ~Fillable();          //Destructor for fillable
  string getFillColour() const; //Accessor for the fill colour parameter
private:
  string fillColour;
};

//With text class for shapes that contain text within them
class WithText
{
public:
  WithText(string text); //Constructor for WithText, containing one string parameter for the message
  virtual ~WithText();  //Destructor for WithText
  string getText();     //Accessor for the text parameter

private:
  string text;
};

//Square class that is a derived class of shape
class Square : public Shape
{
public:
  Square(int length, int width, string borderColour); //Constructor, adds an additional parameter for the border colour of the square
  virtual ~Square();  //Destructor
  virtual void draw();  //Virtual draw function since it is used in derived classes
  string getBorderColour() const;  //Accessor for the border colour parameter

private:
  string borderColour;
};

//Filled Square class that derives both the square and fillable classes
class FilledSquare : public Square, public Fillable
{
public:
  FilledSquare(int length, int width, string borderColour, string fillColour); //Constructor, adds an additional parameter for the border colour of the square and the fill colour 
  virtual ~FilledSquare(); //Destructor
  virtual void draw();  //Virtual draw function since it is used in derived classes
};

//Filled Text Square class that derives the square, fillable and withtext classes
class FilledTextSquare : public Square, public Fillable, public WithText
{
public:
  FilledTextSquare(int length, int width, string borderColour, string fillColour, string text); //Constructor, adds an additional parameter for the border colour of the square, the fill colour and the text within it 
  virtual ~FilledTextSquare(); //Destructor
  virtual void draw(); //while in this specific case this does not have to be virtual (since no class derives this class), in the future, technically another class could derive this one and virtual would be necessary
};

//Circle class that derives the Shape class
class Circle : public Shape
{
public:
  Circle(int length, int width, string borderColour); //Constructor, adds an additional parameter for the border colour of the circle
  virtual ~Circle();  //Destructor   
  virtual void draw();  //Virtual draw function since it is used in derived classes
  string getBorderColour() const; //Accessor for the border colour
private:
  string borderColour;
};

//Filled Circle class that derives the circle and fillable classes
class FilledCircle : public Circle, public Fillable
{
public:
  FilledCircle(int length, int width, string borderColour, string fillColour); //Constructor, adds an additional parameter for the border colour of the circle and the fill colour
  virtual ~FilledCircle(); //Destructor   
  virtual void draw(); //while in this specific case this does not have to be virtual (since no class derives this class), in the future, technically another class could derive this one and virtual would be necessary
};

//Arc class that derives the shape class
class Arc : public Shape
{
public:
  Arc(int length, int width, string borderColour); //Constructor, adds an additional parameter for the border colour of the arc
  virtual ~Arc(); //Destructor  
  virtual void draw(); //while in this specific case this does not have to be virtual (since no class derives this class), in the future, technically another class could derive this one and virtual would be necessary
  string getBorderColour() const; //Accessor for the border colour
private:
  string borderColour;
};

#endif
