<template>
  <!-- rostopic pub -r 10 /cmd_vel geometry_msgs/Twist "linear:
    x: -0.05
    y: 0.0
    z: 0.0
  angular:
    x: 0.0
    y: 0.0
    z: 0.0" -->
    
  
  <div class="row">
    <div class="col-6" style="width: 18em; height: 18em;">
      <div class="row mb-3" style="text-align: left; color: white"><h4>수동 조작키</h4></div>
      <div class="row">
        <div class="col-3 m-1"></div>
        <button class="btn btn-primary col-3 m-1" @click="upEvent">
          <img :src="upSVG" style="width: 100%; height: 100%"/>
        </button>
        <div class="col-3 m-1"></div>
      </div>
      <div class="row">
        <button class="btn btn-primary col-3 m-1" @click="leftEvent">
          <img :src="leftSVG" style="width: 100%; height: 100%"/>
        </button>
        <button class="btn btn-light col-3 m-1" @click="stopEvent">
          <img :src="stopSVG" style="width: 100%; height: 100%"/>
        </button>
        <button class="btn btn-primary col-3 m-1" @click="rightEvent">
          <img :src="rightSVG" style="width: 100%; height: 100%"/>
        </button>
        </div>
      <div class="row">
          <div class="col-3 m-1"></div>
          <button class="btn btn-primary col-3 m-1" @click="downEvent">
            <img :src="downSVG" style="width: 100%; height: 100%"/>
          </button>
          <div class="col-3 m-1"></div>
      </div>
    </div>
    <div class="col-6" style="width: 18em; height: 18em;">
      <div class="row mb-3" style="text-align: left; color: white"><h4>주행 조작키</h4></div>
      <div class="row">
        <div class="col-3 m-1"></div>
        <button class="btn btn-primary col-3 m-1">
          <img :src="upSVG" style="width: 100%; height: 100%"/>
        </button>
        <div class="col-3 m-1"></div>
      </div>
      <div class="row">
        <button class="btn btn-primary col-3 m-1">
          <img :src="leftSVG" style="width: 100%; height: 100%"/>
        </button>
        <button class="btn btn-light col-3 m-1">
          <img :src="stopSVG" style="width: 100%; height: 100%"/>
        </button>
        <button class="btn btn-primary col-3 m-1">
          <img :src="rightSVG" style="width: 100%; height: 100%"/>
        </button>
        </div>
      <div class="row">
          <div class="col-3 m-1"></div>
          <button class="btn btn-primary col-3 m-1">
            <img :src="downSVG" style="width: 100%; height: 100%"/>
          </button>
          <div class="col-3 m-1"></div>
      </div>
    </div>
  </div>
</template>

<script setup>
import axios from 'axios';
import { ref } from 'vue';
import ROSLIB from 'roslib';
import upSVG from '../assets/up.svg';
import downSVG from '../assets/down.svg';
import leftSVG from '../assets/left.svg';
import rightSVG from '../assets/right.svg';
import stopSVG from '../assets/stop.svg';

let isRunning = false;

// *** ros *** //
const ros = new ROSLIB.Ros({
  url: 'ws://localhost:9090'
});

ros.on('connection', () => {
  console.log('Connected to websocket server.');
  connection.value = true;
  connection_text.value = 'Connected';
});

ros.on('error', (error) => {
  console.log('Error to connect websocket server: ', error);
  connection.value = false;
  connection_text.value = 'ERROR';
});

ros.on('close', () => {
  console.log('Connection to websocket server closed.');
  connection.value = false;
  connection_text.value = 'Disconnected';
});

const cmd_vel_listener = new ROSLIB.Topic({
    ros : ros,
    name : "/cmd_vel",
    messageType : 'geometry_msgs/Twist',

  });

const upEvent = async () => {
  const twist = new ROSLIB.Message({
    linear: {
      x: 0.15,
      y: 0.0,
      z: 0.0,
    },
    angular: {
      x: 0.0,
      y: 0.0,
      z: 0.0,
    }
  });

  isRunning = true;
  for (let i=0; i<20000; i++) {
    if (isRunning) {
      cmd_vel_listener.publish(twist);
    }
  }
};

const downEvent = async () => {
  const twist = new ROSLIB.Message({
    linear: {
      x: -0.15,
      y: 0.0,
      z: 0.0,
    },
    angular: {
      x: 0.0,
      y: 0.0,
      z: 0.0,
    }
  });

  isRunning = true;
  for (let i=0; i<20000; i++) {
    if (isRunning) {
      cmd_vel_listener.publish(twist);
    }
  }
};

const leftEvent = async () => {
  const twist = new ROSLIB.Message({
    linear: {
      x: 0.0,
      y: 0.0,
      z: 0.0,
    },
    angular: {
      x: 0.0,
      y: 0.0,
      z: 0.15,
    }
  });

  isRunning = true;
  for (let i=0; i<20000; i++) {
    if (isRunning) {
      cmd_vel_listener.publish(twist);
    }
  }
}

const rightEvent = async () => {
  const twist = new ROSLIB.Message({
    linear: {
      x: 0.0,
      y: 0.0,
      z: 0.0,
    },
    angular: {
      x: 0.0,
      y: 0.0,
      z: -0.15,
    }
  });

  isRunning = true;
  for (let i=0; i<20000; i++) {
    if (isRunning) {
      cmd_vel_listener.publish(twist);
    }
  }
}

const stopEvent = async () => {
  isRunning = false;
  const twist = new ROSLIB.Message({
    linear: {
      x: 0.0,
      y: 0.0,
      z: 0.0,
    },
    angular: {
      x: 0.0,
      y: 0.0,
      z: 0.0,
    }
  });

  for (let i=0; i<100; i++) {
    cmd_vel_listener.publish(twist);
  }
}

</script>