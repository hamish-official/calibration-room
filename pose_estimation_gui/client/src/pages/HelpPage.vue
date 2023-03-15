<template>
  <div class="row mt-5">
    <div class="col-6">
      <div class="card shadow mb-4">
        <div class="card-body p-3">
          <span class="mb-4"><b>1. 초기 세팅 방법</b></span><br/><br/>
          <ul>
            <li><b>
              pose_estimation_gui 관련 초기 설정
            </b></li>
            <br/>$ sudo apt install nodejs
            <br/>$ sudo apt install npm
            <br/>$ sudo npm install -g n
            <br/>$ sudo n 16.18.0
            <br/>$ hash -r
            <br/>$ sudo n # 16.18.0 를 방향키를 통해 선택한 뒤 Enter
            <br/>$ node --version # v16.18.0
            <br/>$ sudo npm install -g typescript
            <br/>$ sudo npm install -g @microsoft/rush # 9.6.1 version
            <br/>$ cd ~/calibration-room/pose_estimation_gui
            <br/>$ rush purge  # 이전 node_modules 초기화
            <br/>$ rush update # package.json에 명세된 패키지로 일괄 설치
            <br/><br/>
            <li><b>
              auto_pose_estimation 관련 초기 설정
            </b></li>
            <br/> $ sudo apt install libgflags-dev ros-noetic-image-geometry ros-noetic-camera-info-manager ros-noetic-image-transport
            <br/> $ sudo apt install ros-noetic-image-publisher libgoogle-glog-dev libusb-1.0-0-dev libeigen3-dev
            <br/> $ sudo apt install ros-noetic-tf2-ros ros-noetic-tf2-web-republisher ros-noetic-rosbridge-server
            <br/>
            <br/> $ cd ~/calibration-room/auto_pose_estimation
            <br/> $ catkin_make -j4
            <br/> 
            <br/> # auto_pose_estimation/src/lidar_pose_estimator/data/lidar_01_reference.txt 내용을 복사
            <br/> $ gedit lidar_01_reference.txt
            <br/> # auto_pose_estimation/src/lidar_pose_estimator/data/lidar_02_reference.txt 내용을 복사
            <br/> $ gedit lidar_02_reference.txt
            <br/>
            <br/> $ sudo mv lidar_01_reference.txt ~/.ros
            <br/> $ sudo mv lidar_02_reference.txt ~/.ros
            <br/><br/>
          </ul>
        </div>
      </div>
    </div>
    
    <div class="col-6">
      <div class="card shadow mb-4">
        <div class="card-body p-3">
          <span class="mb-4"><b>2. 환경 변수 설정 방법</b></span><br/><br/>
          <ul>
            <li><b>
              $ vim ~/.bashrc # 다음의 내용을 주석을 제거한 뒤 추가
            </b></li>
            <br/># alias main='ssh cona@192.168.2.2 -XC'
            <br/># alias sub='ssh cona@192.168.2.3 -XC'
            <br/>
            <br/># alias be='npm run dev --prefix ~/calibration-room/pose_estimation_gui/server'
            <br/># alias fe='npm run dev --prefix ~/calibration-room/pose_estimation_gui/client'
            <br/>
            <br/># export ROS_HOSTNAME=192.168.2.8 # 현재 서빙고 와이파이에 연결된 컴퓨터의 아이피가 192.168.2.8 이라고 가정
            <br/># export ROS_MASTER_URI=http://192.168.2.2:11311
            <br/>
            <br/># source /opt/ros/noetic/setup.bash
            <br/># source ~/calibration-room/auto_pose_estimation/devel/setup.bash
            <br/><br/>
            <li><b>
              $ source ~/.bashrc
            </b></li>
            <br/><br/>
          </ul>
        </div>
      </div>
      <div class="card shadow mb-4">
        <div class="card-body p-3">
          <span class="mb-4"><b>3. 사용 방법</b></span><br/><br/>
          <ul>
            <li class="mb-2">[터미널 1] $ fe</li>
            <li class="mb-2">[터미널 2] $ be</li>
            <li class="mb-2">[브라우저] http://localhost:5173 접속</li>
          </ul>
        </div>
      </div>
    </div>

  </div>
</template>