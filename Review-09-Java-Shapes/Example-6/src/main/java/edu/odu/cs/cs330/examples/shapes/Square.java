// Thomas Kennedy
// CS 330 Fall 2018

package edu.odu.cs.cs330.examples.shapes;

import java.util.Scanner;

/**
 * A Rectangle with 4 Equal Sides.
 *
 * @author Thomas J Kennedy
 */
public class Square extends Shape implements Cloneable {
    /**
     * Length of One Side.
     */
    private double _side;

    /**
     * Construct a Square with side set to 1.
     */
    public Square()
    {
        super("Square");
        _side = 1;
    }

    /**
     * Construct a Square.
     *
     * @param s the desired side length
     */
    public Square(double s)
    {
        super("Square");
        _side = s;
    }

    /**
     * Construct a Square.
     *
     * @param src the Square to copy
     */
    public Square(Square src)
    {
        super("Square");
        this._side = src._side;
    }

    /**
     * Return the side length.
     *
     * @return length of a single side
     */
    public double side()
    {
        return _side;
    }

    /**
     * Modify the side length.
     *
     * @param s the replacement length
     */
    public void side(double s)
    {
        _side = s;
    }

    /**
     * Compute the area.
     *
     * @return area
     */
    public double area()
    {
        return Math.pow(_side, 2.0);
    }

    /**
     * Compute the perimeter.
     *
     * @return perimeter
     */
    public double perimeter()
    {
        return 4 * _side;
    }

    /**
     * Return a new duplicate Square.
     */
    @Override
    public Object clone() throws CloneNotSupportedException
    {
        return new Square(this);
    }

    /**
     * Read the shape.
     *
     * @param scanner the input stream--scanner in this example
     */
    @Override
    public void read(Scanner scanner)
    {
        this._side = scanner.nextDouble();
    }

    /**
     * Print the Square.
     */
    @Override
    public String toString()
    {
        return super.toString()
             + String.format(FMT_DBL, "Side", this._side)
             + String.format(FMT_DBL, "Perimeter", this.perimeter())
             + String.format(FMT_DBL, "Area", this.area());
    }
}




