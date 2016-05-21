#include "RM.h"
#include <iostream>

int main()
{
	RM::vedio_stream.open("RedCar.mp4");
	cv::Mat r_frame;
	cv::Mat b_frame;
	
	std::vector<cv::RotatedRect> targets;
	while(true)
	{
		RM::vedio_stream>>r_frame;

		if(r_frame.empty())
		{
			std::cout<<"The end."<<std::endl;
			break;
		}
		//RM::img_init(r_frame);
		RM::get_binary(r_frame,b_frame);
		
		cv::imshow("b_frame",b_frame);
		cv::waitKey(1);

		RM::get_targets(r_frame,b_frame,targets);
		RM::draw_boxes(r_frame,targets);	

		cv::imshow("RM",r_frame);
		cv::waitKey(1);
		targets.clear();
	}

	
	return 0;
}