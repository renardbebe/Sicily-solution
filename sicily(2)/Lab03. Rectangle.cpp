	Rectangle::Rectangle() 
    {
        width=1;
        height=1;
    }
    Rectangle::Rectangle(double Width, double Height)
    {
        width=Width;
        height=Height;
    }
    double Rectangle::getWidth()
    {
        return width;
    }
    double Rectangle::getHeight()
    {
        return height;
    }
    void Rectangle::setWidth(double Width)
    {
        width=Width;
    }
    void Rectangle::setHeight(double Height)
    {
        height=Height;
    }
    double Rectangle::getArea()
    {
        return width*height;
    }
    double Rectangle::getPerimeter()
    {
        return 2*(width+height);
    }
