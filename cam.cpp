#include <iostream>
#include "opencv/cv.h"
#include "opencv/highgui.h"
using namespace std;
 
int main()
{
    // Create the webcam window.
    cvNamedWindow( "CAMERA_STREAM", CV_WINDOW_AUTOSIZE );
    // Open the video stream using any connected cam.
 	CvCapture* stream = cvCaptureFromCAM( CV_CAP_ANY );

    if ( !stream )
	{
	    cout << "ERROR: The stream is null!\n";
	    return -1;
	}
 
    IplImage* frame = NULL;
    
    char keypress;
    bool quit = false;
 
    while( !quit )
    {
        // Get a frame from the cam
        frame = cvQueryFrame( stream );
 		// Draw it to the window
        cvShowImage("CAMERA_STREAM", frame );
 		// Wait 20ms
        keypress = cvWaitKey(20);
 		// Turn on the exit flag if the user presses escape.
        if (keypress == 27) quit = true;
        	
    }
 
    // Cleaning up.
    cvReleaseImage( &frame );
    cvDestroyAllWindows();
}