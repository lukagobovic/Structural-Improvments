/*
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
#include <ostream>
using namespace std;

class Shape
{
public:
  Shape(int length, int width);
  virtual ~Shape(); // Destructor
  virtual void draw();
  int getLength() const;
  int getWidth() const;

private:
  int length, width;
};

class Fillable
{
public:
  Fillable (string fillColour);
  virtual ~Fillable();
  string getFillColour() const;

private:
  string fillColour;
};

class WithText
{
public:
  WithText(string text);
  virtual ~WithText();
  string getText();

private:
  string text;
};

class Square : public Shape
{
public:
  Square(int length, int width, string borderColour);
  virtual ~Square();
  virtual void draw();
  string getBorderColour() const;

private:
  string borderColour;
};

class FilledSquare : public Square, public Fillable
{
public:
  FilledSquare(int length, int width, string borderColour, string fillColour);
  virtual ~FilledSquare();
  virtual void draw();
};

class FilledTextSquare : public Square, public Fillable, public WithText
{
public:
  FilledTextSquare(int length, int width, string borderColour, string fillColour, string text);
  virtual ~FilledTextSquare();
  virtual void draw();
};

class Circle : public Shape
{
public:
  Circle(int length, int width, string borderColour);
  virtual ~Circle();
  virtual void draw();
  string getBorderColour() const;
private:
  string borderColour;
};

class FilledCircle : public Circle, public Fillable
{
public:
  FilledCircle(int length, int width, string borderColour, string fillColour);
  virtual ~FilledCircle();
  virtual void draw();
};

class Arc : public Shape
{
public:
  Arc(int length, int width, string borderColour);
  virtual ~Arc();
  virtual void draw();
  string getBorderColour() const;
private:
  string borderColour;
};

#endif
