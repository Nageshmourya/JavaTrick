
{
result[i]='_';
}
for (int i = 0; i < x; i++)
{
for(int j = 0;j < 10; j++)
{
//Check if the template is valid for cvmatchtemplate function
if(((templates[j]->width)>(frame_buffer1[numberpositions[i]]->width))||
((templates[j]->height)>(frame_buffer1[numberpositions[i]]->height)))
{
continue;
}
//Make iplimage for cvmatchtemplate function result
IplImage* imgResult =
cvCreateImage(cvSize(frame_buffer1[numberpositions[i]]->width - templates[j]->width + 1 ,
frame_buffer1[numberpositions[i]]->height - templates[j]->height + 1), IPL_DEPTH_32F, 1);
cvZero(imgResult);
cvMatchTemplate(frame_buffer1[numberpositions[i]], templates[j],imgResult,
CV_TM_SQDIFF);
double min_val=0, max_val=0,maxx=0, minn=0;
CvPoint min_loc, max_loc;
cvMinMaxLoc(imgResult, &min_val, &max_val, &min_loc, &max_loc);
cvReleaseImage( &imgResult );
char temp11[20], temp12[20];
sprintf( temp11, "%d", max_val );
sprintf( temp12, "%d", min_val );
//Check if the result is 0, if not, check for the next template
if(temp11[0]!='0')
{
continue;
}
if(temp12[0]!='0')
{
continue;
}
result[i]=templatename[j];
printf("number added to the result = %c \n", templatename[j]);
break;
}
}
//Print the result
for(int i=0;i<10;i++)
{
printf("%c",result[i]);
}
cvWaitKey(0);
/* free memory */
cvDestroyWindow( "image" );
cvReleaseImage( &img );
cvReleaseImage(&cc_color);
return 0;
} nagesh kumar