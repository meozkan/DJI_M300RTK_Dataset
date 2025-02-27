include=-I../../include
libpath=-L../../lib
libs=#-l

all:build/DJI_M300RTK_Dataset_Coordinator

build/DJI_M300RTK_Dataset_Coordinator: 
	g++ DJI_M300RTK_Dataset_Coordinator.cpp $(include) $(libpath) $(libs) -o build/DJI_M300RTK_Dataset_Coordinator 

.PHONY: clean
clean:
	@rm -f ./build/DJI_M300RTK_Dataset_Coordinator