/*
 * Luka Gobovic - 20215231
 * Assignment 4
 * ShapesGood implementation file
 * December 5th, 2022
 * 
 * This is the implementation of the bad structure built in the header file.  Instead of
 * drawing anything, you can see that the various drawing functions just display some text
 * to the console to indicate what the function would be doing.
 *
 * For CISC/CMPE 320, Assignment 5
 */
#include <iostream>
#include <string>
#include "ShapesGood.h"

using namespace std;

// Start of Shape
Shape::Shape(int length, int width)
{
  this->length = length;
  this->width = width;
}
// Destructor
Shape::~Shape() {}

void Shape::draw()
{
  cout << "Base case, nothing to draw." << endl; // base case
}

int Shape::getLength() const
{
  return this->length;
}
int Shape::getWidth() const
{
  return this->width;
}

//------------------------------------------------------------
// Start of Fillable
Fillable::Fillable(string colour)
{
  this->fillColour = colour;
}

Fillable::~Fillable() {}

string Fillable::getFillColour() const
{
  return this->fillColour;
}

//------------------------------------------------------------
// Start of WithText
WithText::WithText(string text)
{
  this->text = text;
}

WithText::~WithText() {}

string WithText::getText()
{
  return this->text;
}

//------------------------------------------------------------
// Start of Square
Square::Square(int length, int width, string borderColour) : Shape(length, width)
{
  this->borderColour = borderColour;
}

Square::~Square() {}

void Square::draw()
{
  cout << "\nDrawing a " + getBorderColour() + " square.";
}

string Square::getBorderColour() const
{
  return this->borderColour;
}

//------------------------------------------------------------
// Start of Filled Square
FilledSquare::FilledSquare(int length, int width, string borderColour, string fillColour) : Square(length, width, borderColour), Fillable(fillColour) {}

FilledSquare::~FilledSquare() {}

void FilledSquare::draw()
{
  cout << "\nDrawing a " + getBorderColour() + " square. With " + getFillColour() + " fill.";
}

//------------------------------------------------------------
// Start of Filled Text Square
FilledTextSquare::FilledTextSquare(int length, int width, string borderColour, string fillColour, string text) : Square(length, width, borderColour), Fillable(fillColour), WithText(text) {}

FilledTextSquare::~FilledTextSquare() {}

void FilledTextSquare::draw()
{
  cout << "\nDrawing a " + getBorderColour() + " square. With " + getFillColour() + " fill. Containing the text: " + getText();
}

//------------------------------------------------------------
// Start of Circle
Circle::Circle(int length, int width, string borderColour) : Shape(length, length)
{
  this->borderColour = borderColour;
}

Circle::~Circle() {}

string Circle::getBorderColour() const
{
  return this->borderColour;
}

void Circle::draw()
{
  cout << "\nDrawing a " + getBorderColour() + " circle.";
}

//------------------------------------------------------------
// Start of Filled Circle
FilledCircle::FilledCircle(int length, int width, string borderColour, string fillColour) : Circle(length, width, borderColour), Fillable(fillColour) {}

FilledCircle::~FilledCircle() {}

void FilledCircle::draw()
{
  cout << "\nDrawing a " + getBorderColour() + " circle. With " + getFillColour() + " fill.";
}

Arc::Arc(int length, int width, string borderColour) : Shape(length, width)
{
  this->borderColour = borderColour;
}

//------------------------------------------------------------
// Start of Arc
Arc::~Arc() {}

string Arc::getBorderColour() const
{
  return this->borderColour;
}

void Arc::draw()
{
  cout << "\nDrawing a " + getBorderColour() + " arc.";
}
