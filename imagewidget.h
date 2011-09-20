/* 
 * File:   imagewidget.h
 * Author: zian
 *
 * Created on 19 de septiembre de 2011, 19:34
 */

#ifndef IMAGEWIDGET_H
#define	IMAGEWIDGET_H

#include <QtGui>
#include <QWidget>
#include <QVTKWidget.h>

#include <vtkRenderer.h>
#include <vtkImageActor.h>
#include <vtkRenderWindow.h>
#include <vtkSmartPointer.h>
#include <vtkImageData.h>


#include <itkImage.h>

#include "external/itkVTKImageToImageFilter.h"
#include "external/itkImageToVTKImageFilter.h"


typedef itk::Image< unsigned char, 2 > ImageType;
typedef itk::VTKImageToImageFilter <ImageType> itkConnectorType;
typedef itk::ImageToVTKImageFilter <ImageType> vtkConnectorType;

class ImageWidget : public QWidget {
    
    Q_OBJECT
    
public:
     /** 
      * Constructor for this ImageWidget 
      */
    ImageWidget(QWidget *parent = 0);

    /** 
     * Destructor for this ImageWidget 
     */
    virtual ~ImageWidget();

    /**
     * load an display an image from file
     */
    void open();
    
    /**
     * load an display an image from file
     */
    void openWithITK();
    
    /**
     * Apply a median fiter to the itkImage
     */
    void medianFilter();
    
private:
    
    QVTKWidget *qvtkWidget;
    
    /** The image displayed for this window */
    ImageType::Pointer itkImage;

    /** The VTK image to display in this window */
    vtkSmartPointer <vtkImageData> vtkImage;
        
    vtkSmartPointer<vtkImageActor> actor;
    vtkSmartPointer<vtkRenderer> renderer;
    vtkSmartPointer<vtkRenderWindow> renderWindow;
    
     /** The type of the image components RGB, scalar, etc */
    std::string pixelType;

    /** The type of the image pixels */
    std::string imageType;

    /** The number of the image dimensions */
    size_t numDimensions;
    
    /**
     * to display the loaded image in the QVTKwidget
     * @param image vtkImageData
     */
    void displayImage(vtkImageData *image);
    
    /**
     * Set itkImage converting the vtkImage to a ITK image
     */
    void setITKImageFromVTK();
    
    /**
     * extract some image properties as, pixel type, image type and number of dimensions
     * @param fileName path to the file 
     * @param vervose if print the standar out 
     */
    void setImageProperties(std::string fileName, bool vervose);

};

#endif	/* IMAGEWIDGET_H */

