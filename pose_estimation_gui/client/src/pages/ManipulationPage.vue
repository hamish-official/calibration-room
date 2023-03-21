<template>
  <div class="row">
    <div class="col-12">
      <div class="container">
        <div class="margin-bottom-basic mb-4">
          <h5>로봇의 수동 조작 및 자율 주행 조작을 지원합니다.</h5>
          <span style="color:grey;">
            작동 상태는 '
            <span v-if="connection" style="color: green">{{ connection_text }}</span>
            <span v-else style="color: red">{{ connection_text }}</span>
            '이며, 연결된 아이피는
            {{ (ip) ? ip + ' 입니다.' : '없습니다.' }}
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
              <img :src="upSVG" style="width: 90%; height: 90%"/>
            </button>
            <div class="col-4"></div>
          </div>
          <div class="row">
            <button class="btn btn-secondary col-4" @click="leftEvent">
              <img :src="leftSVG" style="width: 90%; height: 90%"/>
            </button>
            <button class="btn btn-light col-4" @click="stopEvent">
              <img :src="stopSVG" style="width: 90%; height: 90%"/>
            </button>
            <button class="btn btn-secondary col-4" @click="rightEvent">
              <img :src="rightSVG" style="width: 90%; height: 90%"/>
            </button>
            </div>
          <div class="row">
              <div class="col-4"></div>
              <button class="btn btn-secondary col-4" @click="downEvent">
                <img :src="downSVG" style="width: 90%; height: 90%"/>
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
            <button class="btn btn-secondary col-12" style="height:5em;" @click="servingEvent('홈')">
              <h1>홈</h1>
            </button>
          </div>
          <div class="row mb-3">
            <button class="btn btn-secondary col-12" style="height:5em;" @click="servingEvent('1')">
              <h1>1</h1>
            </button>
          </div>
          <div class="row mb-3">
            <button class="btn btn-secondary col-12" style="height:5em;" @click="servingEvent('2')">
              <h1>2</h1>
            </button>
          </div>
          <div class="row mb-3">
            <button class="btn btn-secondary col-12" style="height:5em;" @click="servingEvent('3')">
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
import { ref } from 'vue';
import ROSLIB from 'roslib';
import upSVG from '../assets/up.svg';
import downSVG from '../assets/down.svg';
import leftSVG from '../assets/left.svg';
import rightSVG from '../assets/right.svg';
import stopSVG from '../assets/stop.svg';

// *** axios default settings *** //
axios.defaults.baseURL = 'http://192.168.2.2:5000';
axios.defaults.headers.post['Content-Type'] = 'application/json;charset=utf-8';
axios.defaults.headers.post['Access-Control-Allow-Origin'] = '*';

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
}

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
}

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
}

const getMaps = async () => {
  const data = await axios({
    url: 'api/v1',
    method: 'post',
    data: {
      cmd: 'getMaps'
    }
  })
};

async function servingEvent(goal_name) {
  let data;

  try {
    data = await axios({
      url: 'ap/v1',
      cmd: 'setRobot',
      value: {
        state: 'going',
        mode: 'serving',
        goals: [{
          table: goal_name,
          tray: [0],
        }],
        nextGoal: {table: '', tray: []}
      }
    });
  }
  catch (err) {
    console.error(err);
  }

  console.log(data);
}
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
}
</style>