/*
 * This is the implementation of the bad structure built in the header file.  Instead of
 * drawing anything, you can see that the various drawing functions just display some text
 * to the console to indicate what the function would be doing.
 *
 * For CISC/CMPE 320, Assignment 5
 */
#include <iostream>
#include <string>
#include <ostream>
#include "ShapesGood.h"

using namespace std;

// SHAPE IMPLEMENTATION
Shape::Shape(int length, int width)
{
  this->length = length;
  this->width = width;
}

void Shape::draw(){
  cout << "Base case, nothing to draw." << endl;
}

int Shape::getLength() const
{
  return this->length;
}
int Shape::getWidth() const
{
  return this->width;
}

Fillable::Fillable(string colour){
  this->fillColour = colour;
}


string Fillable::getFillColour() const{
  return this->fillColour;
}

WithText::WithText(string text){
  this->text = text;
}


string WithText::getText(){
  return this->text;
}
// END OF SHAPE

// START OF SQUARE
Square::Square(int length, int width, string borderColour) : Shape(length, width)
{
  this->borderColour = borderColour;
}

void Square::draw()
{
  cout << "\nDrawing a " + getBorderColour() + " square.";
}

string Square::getBorderColour() const
{
  return this->borderColour;
}


// Filled Square
FilledSquare::FilledSquare(int length, int width, string borderColour, string fillColour) : Square(length, width, borderColour), Fillable(fillColour) {}

void FilledSquare::draw()
{
  cout << "\nDrawing a " + getBorderColour() + " square. With " + getFillColour() + " fill.";
}

// Filled Text Square
FilledTextSquare::FilledTextSquare(int length, int width, string borderColour, string fillColour, string text) : Square(length, width, borderColour), Fillable(fillColour), WithText(text) {}
void FilledTextSquare::draw()
{
  cout << "\nDrawing a " + getBorderColour() + " square. With " + getFillColour() + " fill. Containing the text: " + getText();
}

//Circle
Circle::Circle(int length, int width, string borderColour) : Shape(length, length)
{
  this->borderColour = borderColour;
}

string Circle::getBorderColour() const
{
  return this->borderColour;
}

void Circle::draw()
{
   cout << "\nDrawing a " + getBorderColour() + " circle.";
}

FilledCircle::FilledCircle(int length, int width, string borderColour, string fillColour) : Circle(length, width, borderColour), Fillable(fillColour){}

void FilledCircle::draw()
{
   cout << "\nDrawing a " + getBorderColour() + " circle. With " + getFillColour() + " fill.";
}

Arc::Arc(int length, int width, string borderColour) : Shape(length, width) {
  this->borderColour = borderColour;
}

string Arc::getBorderColour() const{
  return this->borderColour;
}

void Arc::draw()
{
  cout << "\nDrawing a " + getBorderColour() + " arc.";
}


Shape::~Shape() {}

Fillable::~Fillable() {}

WithText::~WithText() {}

Square::~Square(){}

FilledSquare::~FilledSquare(){}

FilledTextSquare::~FilledTextSquare(){}

Circle::~Circle(){}

FilledCircle::~FilledCircle(){}

Arc::~Arc(){}
