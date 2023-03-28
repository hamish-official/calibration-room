<template>
  <div class="row">
    <div class="col-12">
      <div class="container">
        <div class="margin-bottom-basic mb-4">
          <h5>로봇의 수동 조작 및 자율 주행 조작을 지원합니다.</h5>
          <span style="color:grey;">
            수동 조작 버튼으로 캘리브레이션 공간을 빠져나온 뒤 자율 주행 버튼을 조작하시기 바랍니다.
          </span>
        </div>
      </div>
    </div>

    <div class="col-6 p-3">
      <div class="card p-3">
        <div class="container mb-4">
          <h4>수동 조작 버튼</h4>
          <hr/>
        </div>
        <div class="container">
          <div class="row">
            <div class="col-4"></div>
            <button class="btn btn-secondary col-4" @click="upEvent">
              <img :src="upSVG" style="height: 6em;"/>
            </button>
            <div class="col-4"></div>
          </div>
          <div class="row">
            <button class="btn btn-secondary col-4" @click="leftEvent">
              <img :src="leftSVG" style="height: 6em;"/>
            </button>
            <button class="btn btn-light col-4" @click="stopEvent">
              <img :src="stopSVG" style="height: 6em;"/>
            </button>
            <button class="btn btn-secondary col-4" @click="rightEvent">
              <img :src="rightSVG" style="height: 6em;"/>
            </button>
            </div>
          <div class="row">
              <div class="col-4"></div>
              <button class="btn btn-secondary col-4" @click="downEvent">
                <img :src="downSVG" style="height: 6em;"/>
              </button>
              <div class="col-4"></div>
          </div>
        </div>
      </div>
    </div>
    
    <div class="col-6 p-3">
      <div class="card p-3">
        <div class="container mb-4">
          <h4>자율 주행 버튼</h4>
          <hr/>
        </div>
        <div class="container">
          <div class="row mb-3">
            <button class="btn btn-secondary col-12" style="height:5em;" @click="servingHome">
              <h1>홈</h1>
            </button>
          </div>
          <div class="row mb-3">
            <button class="btn btn-secondary col-12" style="height:5em;" @click="servingOne">
              <h1>1</h1>
            </button>
          </div>
          <div class="row mb-3">
            <button class="btn btn-secondary col-12" style="height:5em;" @click="servingTwo">
              <h1>2</h1>
            </button>
          </div>
          <div class="row mb-3">
            <button class="btn btn-secondary col-12" style="height:5em;" @click="servingThree">
              <h1>3</h1>
            </button>
          </div>
        </div>
      </div>
    </div>

  </div>
</template>

<script setup>
import axios from 'axios';
// import { ref } from 'vue';
import ROSLIB from 'roslib';
import upSVG from '../assets/up.svg';
import downSVG from '../assets/down.svg';
import leftSVG from '../assets/left.svg';
import rightSVG from '../assets/right.svg';
import stopSVG from '../assets/stop.svg';

// // *** axios default settings *** //
// const AxiosInst = axios.create({
//   baseURL : 'http://192.168.2.2:5000',
//   headers: {
//         "Access-Control-Allow-Origin": `http://localhost:3000`,
//         'Access-Control-Allow-Credentials':"true",
//     }
// });

// *** ros *** //
const ros = new ROSLIB.Ros({
  url: 'ws://localhost:9090'
});

ros.on('connection', () => {
  console.log('Connected to websocket server.');
});

ros.on('error', (error) => {
  console.log('Error to connect websocket server: ', error);
});

ros.on('close', () => {
  console.log('Connection to websocket server closed.');
});

const cmd_vel_listener = new ROSLIB.Topic({
  ros : ros,
  name : "/cmd_vel",
  messageType : 'geometry_msgs/Twist',
});

let interval_id;

let twist = new ROSLIB.Message({
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

function publish_twist() {
  for (let i=0; i<100; i++) {
    cmd_vel_listener.publish(twist);
  }
}

const upEvent = async () => {
  twist = new ROSLIB.Message({
    linear: {
      x: 0.1,
      y: 0.0,
      z: 0.0,
    },
    angular: {
      x: 0.0,
      y: 0.0,
      z: 0.0,
    }
  });

  interval_id = setInterval(()=>(publish_twist()), 100);
};

const downEvent = async () => {
  twist = new ROSLIB.Message({
    linear: {
      x: -0.1,
      y: 0.0,
      z: 0.0,
    },
    angular: {
      x: 0.0,
      y: 0.0,
      z: 0.0,
    }
  });

  interval_id = setInterval(()=>(publish_twist()), 100);
};

const leftEvent = async () => {
  twist = new ROSLIB.Message({
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

  interval_id = setInterval(()=>(publish_twist()), 100);
};

const rightEvent = async () => {
  twist = new ROSLIB.Message({
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

  interval_id = setInterval(()=>(publish_twist()), 100);
};

const stopEvent = async () => {
  clearInterval(interval_id);

  twist = new ROSLIB.Message({
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
  
  interval_id = setInterval(publish_twist(0), 100);
  clearInterval(interval_id);
};

const serving = async (goal_name) => {
  let result = null;
  try {
    result = await axios.post("/api/v1", {
      cmd: "setRobot",
      value : {
        state : "going",
        mode : "serving",
        goals :[
          { table : goal_name, tray : [0] }
        ],
        nextGoal: { table: "", tray: [] }
      },
    });
    console.log(result);
  }
  catch (err) {
    console.error(err.message);
  }
}

const servingOne = async () => { serving('1') };
const servingTwo = async () => { serving('2') };
const servingThree = async () => { serving('3') };
const servingHome = async() => { serving('홈') };

</script>

<style scoped>
body {
  max-width: 1280px;
  display: inline-block;
  margin: .1em;
  min-width: 15em;
}

.card {
  min-height: 32em;
  max-height: 32em;
}
</style>