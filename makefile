include=-I../../include
libpath=-L/home/lattepanda/git/RIS_122E408_Project/Optitrack_NatNet_SDK_4_1_Ubuntu/lib/
libs=#-l

all:build/DJI_M300RTK_Dataset_Coordinator

build/DJI_M300RTK_Dataset_Coordinator: 
	g++ DJI_M300RTK_Dataset_Coordinator.cpp $(include) $(libpath) $(libs) -o build/DJI_M300RTK_Dataset_Coordinator 

.PHONY: clean
clean:
	@rm -f ./build/DJI_M300RTK_Dataset_Coordinator