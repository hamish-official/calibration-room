<template>
  <div class="mt-5">
    <div class="row mb-3 d-flex justify-content-center">
      <button type="button" class="col-2 btn btn-primary v-mar"  @click="store_pose"><strong>STORE<br/>POSE</strong></button>&nbsp;&nbsp;
      <button type="button" class="col-2 btn btn-dark v-mar" @click="all_lidar_reference"><strong>ALL LIDAR<br/>REFERENCE</strong></button>&nbsp;&nbsp;
      <button type="button" class="col-2 btn btn-dark v-mar" @click="lidar_1_current"><strong>LIDAR 1<br/>CURRENT</strong></button>&nbsp;&nbsp;
      <button type="button" class="col-2 btn btn-dark v-mar" @click="lidar_2_current"><strong>LIDAR 2<br/>CURRENT</strong></button>&nbsp;&nbsp;
      <button type="button" class="col-2 btn btn-dark v-mar" @click="lidar_3_current"><strong>LIDAR 3<br/>CURRENT</strong></button>
    </div>

    <div class="row mt-5 mb-3">
      <div class="col-md-12">
        <h2>6-DOF Data</h2>
      </div>
    </div>

    <div class="row d-flex justify-content-center">
      <div class="col-md-3">
        <div class="bordered">
          <div class="row">
            <div class="col-md-12">
              <h3 class="no-top">Depth 1</h3>
            </div>
          </div>
          <div class="row">
            <div class="col-md-6">
              <div class="form-group">
                <label for="">x</label>
                <input type="text" class="form-control" id="" :value="depth_1.x.value">
              </div>
            </div>
            <div class="col-md-6">
              <div class="form-group">
                <label for="">y</label>
                <input type="text" class="form-control" id="" :value="depth_1.y.value">
              </div>
            </div>
          </div>
          <div class="row">
            <div class="col-md-6">
              <div class="form-group">
                <label for="">z</label>
                <input type="text" class="form-control" id="" :value="depth_1.z.value">
              </div>
            </div>
            <div class="col-md-6">
              <div class="form-group">
                <label for="">roll</label>
                <input type="text" class="form-control" id="" :value="depth_1.roll.value">
              </div>
            </div>
          </div>
          <div class="row">
            <div class="col-md-6">
              <div class="form-group">
                <label for="">pitch</label>
                <input type="text" class="form-control" id="" :value="depth_1.pitch.value">
              </div>
            </div>
            <div class="col-md-6">
              <div class="form-group">
                <label for="">yaw</label>
                <input type="text" class="form-control" id="" :value="depth_1.yaw.value">
              </div>
            </div>
          </div>
        </div>
      </div>

      <div class="col-md-3">
        <div class="bordered">
          <div class="row">
            <div class="col-md-12">
              <h3 class="no-top">Depth 2</h3>
            </div>
          </div>
          <div class="row">
            <div class="col-md-6">
              <div class="form-group">
                <label for="">x</label>
                <input type="text" class="form-control" id="" :value="depth_2.x.value">
              </div>
            </div>
            <div class="col-md-6">
              <div class="form-group">
                <label for="">y</label>
                <input type="text" class="form-control" id="" :value="depth_2.y.value">
              </div>
            </div>
          </div>
          <div class="row">
            <div class="col-md-6">
              <div class="form-group">
                <label for="">z</label>
                <input type="text" class="form-control" id="" :value="depth_2.z.value">
              </div>
            </div>
            <div class="col-md-6">
              <div class="form-group">
                <label for="">roll</label>
                <input type="text" class="form-control" id="" :value="depth_2.roll.value">
              </div>
            </div>
          </div>
          <div class="row">
            <div class="col-md-6">
              <div class="form-group">
                <label for="">pitch</label>
                <input type="text" class="form-control" id="" :value="depth_2.pitch.value">
              </div>
            </div>
            <div class="col-md-6">
              <div class="form-group">
                <label for="">yaw</label>
                <input type="text" class="form-control" id="" :value="depth_2.yaw.value">
              </div>
            </div>
          </div>
        </div>
      </div>

      <div class="col-md-3">
        <div class="bordered">
          <div class="row">
            <div class="col-md-12">
              <h3 class="no-top">Depth 3</h3>
            </div>
          </div>
          <div class="row">
            <div class="col-md-6">
              <div class="form-group">
                <label for="">x</label>
                <input type="text" class="form-control" id="" :value="depth_3.x.value">
              </div>
            </div>
            <div class="col-md-6">
              <div class="form-group">
                <label for="">y</label>
                <input type="text" class="form-control" id="" :value="depth_3.y.value">
              </div>
            </div>
          </div>
          <div class="row">
            <div class="col-md-6">
              <div class="form-group">
                <label for="">z</label>
                <input type="text" class="form-control" id="" :value="depth_3.z.value">
              </div>
            </div>
            <div class="col-md-6">
              <div class="form-group">
                <label for="">roll</label>
                <input type="text" class="form-control" id="" :value="depth_3.roll.value">
              </div>
            </div>
          </div>
          <div class="row">
            <div class="col-md-6">
              <div class="form-group">
                <label for="">pitch</label>
                <input type="text" class="form-control" id="" :value="depth_3.pitch.value">
              </div>
            </div>
            <div class="col-md-6">
              <div class="form-group">
                <label for="">yaw</label>
                <input type="text" class="form-control" id="" :value="depth_3.yaw.value">
              </div>
            </div>
          </div>
        </div>
      </div>

      <div class="col-md-3">
        <div class="bordered">
          <div class="row">
            <div class="col-md-12">
              <h3 class="no-top">Camera 1</h3>
            </div>
          </div>
          <div class="row">
            <div class="col-md-6">
              <div class="form-group">
                <label for="">x</label>
                <input type="text" class="form-control" id="" :value="camera_1.x.value">
              </div>
            </div>
            <div class="col-md-6">
              <div class="form-group">
                <label for="">y</label>
                <input type="text" class="form-control" id="" :value="camera_1.y.value">
              </div>
            </div>
          </div>
          <div class="row">
            <div class="col-md-6">
              <div class="form-group">
                <label for="">z</label>
                <input type="text" class="form-control" id="" :value="camera_1.z.value">
              </div>
            </div>
            <div class="col-md-6">
              <div class="form-group">
                <label for="">roll</label>
                <input type="text" class="form-control" id="" :value="camera_1.roll.value">
              </div>
            </div>
          </div>
          <div class="row">
            <div class="col-md-6">
              <div class="form-group">
                <label for="">pitch</label>
                <input type="text" class="form-control" id="" :value="camera_1.pitch.value">
              </div>
            </div>
            <div class="col-md-6">
              <div class="form-group">
                <label for="">yaw</label>
                <input type="text" class="form-control" id="" :value="camera_1.yaw.value">
              </div>
            </div>
          </div>
        </div>
      </div>

    </div>
    <div class="row m-2"></div>
    <div class="row d-flex justify-content-center">
      <div class="col-md-3">
        <div class="bordered">
          <div class="row">
            <div class="col-md-12">
              <h3 class="no-top">Lidar 1</h3>
            </div>
          </div>
          <div class="row">
            <div class="col-md-6">
              <div class="form-group">
                <label for="">x</label>
                <input type="text" class="form-control" id="" :value="lidar_1.x.value">
              </div>
            </div>
            <div class="col-md-6">
              <div class="form-group">
                <label for="">y</label>
                <input type="text" class="form-control" id="" :value="lidar_1.y.value">
              </div>
            </div>
          </div>
          <div class="row">
            <div class="col-md-6">
              <div class="form-group">
                <label for="">z</label>
                <input type="text" class="form-control" id="" :value="lidar_1.z.value">
              </div>
            </div>
            <div class="col-md-6">
              <div class="form-group">
                <label for="">roll</label>
                <input type="text" class="form-control" id="" :value="lidar_1.roll.value">
              </div>
            </div>
          </div>
          <div class="row">
            <div class="col-md-6">
              <div class="form-group">
                <label for="">pitch</label>
                <input type="text" class="form-control" id="" :value="lidar_1.pitch.value">
              </div>
            </div>
            <div class="col-md-6">
              <div class="form-group">
                <label for="">yaw</label>
                <input type="text" class="form-control" id="" :value="lidar_1.yaw.value">
              </div>
            </div>
          </div>
        </div>
      </div>

      <div class="col-md-3">
        <div class="bordered">
          <div class="row">
            <div class="col-md-12">
              <h3 class="no-top">Lidar 2</h3>
            </div>
          </div>
          <div class="row">
            <div class="col-md-6">
              <div class="form-group">
                <label for="">x</label>
                <input type="text" class="form-control" id="" :value="lidar_2.x.value">
              </div>
            </div>
            <div class="col-md-6">
              <div class="form-group">
                <label for="">y</label>
                <input type="text" class="form-control" id="" :value="lidar_2.y.value">
              </div>
            </div>
          </div>
          <div class="row">
            <div class="col-md-6">
              <div class="form-group">
                <label for="">z</label>
                <input type="text" class="form-control" id="" :value="lidar_2.z.value">
              </div>
            </div>
            <div class="col-md-6">
              <div class="form-group">
                <label for="">roll</label>
                <input type="text" class="form-control" id="" :value="lidar_2.roll.value">
              </div>
            </div>
          </div>
          <div class="row">
            <div class="col-md-6">
              <div class="form-group">
                <label for="">pitch</label>
                <input type="text" class="form-control" id="" :value="lidar_2.pitch.value">
              </div>
            </div>
            <div class="col-md-6">
              <div class="form-group">
                <label for="">yaw</label>
                <input type="text" class="form-control" id="" :value="lidar_2.yaw.value">
              </div>
            </div>
          </div>
        </div>
      </div>

      <div class="col-md-3">
        <div class="bordered">
          <div class="row">
            <div class="col-md-12">
              <h3 class="no-top">Lidar 3</h3>
            </div>
          </div>
          <div class="row">
            <div class="col-md-6">
              <div class="form-group">
                <label for="">x</label>
                <input type="text" class="form-control" id="" :value="lidar_3.x.value">
              </div>
            </div>
            <div class="col-md-6">
              <div class="form-group">
                <label for="">y</label>
                <input type="text" class="form-control" id="" :value="lidar_3.y.value">
              </div>
            </div>
          </div>
          <div class="row">
            <div class="col-md-6">
              <div class="form-group">
                <label for="">z</label>
                <input type="text" class="form-control" id="" :value="lidar_3.z.value">
              </div>
            </div>
            <div class="col-md-6">
              <div class="form-group">
                <label for="">roll</label>
                <input type="text" class="form-control" id="" :value="lidar_3.roll.value">
              </div>
            </div>
          </div>
          <div class="row">
            <div class="col-md-6">
              <div class="form-group">
                <label for="">pitch</label>
                <input type="text" class="form-control" id="" :value="lidar_3.pitch.value">
              </div>
            </div>
            <div class="col-md-6">
              <div class="form-group">
                <label for="">yaw</label>
                <input type="text" class="form-control" id="" :value="lidar_3.yaw.value">
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>

    <div class="row m-2"></div>

    <div class="row mt-5">
      <div class="col-md-12">
        <h2>Sensor Data</h2>
      </div>
    </div>

    <CarouselComponent :ros="ros" />
  </div>
</template>

<script setup>
import CarouselComponent from '../components/CarouselComponent.vue';
import { ref } from 'vue';
import ROSLIB from 'roslib';
import axios from 'axios';

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

// *** variables *** //
let camera_1, depth_1, depth_2, depth_3, lidar_1, lidar_2, lidar_3;
camera_1 = depth_1 = depth_2 = depth_3 = lidar_1 = lidar_2 = lidar_3 = {
  x: ref('0'),
  y: ref('0'),
  z: ref('0'),
  roll: ref('0'),
  pitch: ref('0'),
  yaw: ref('0'),
};

// *** axios *** //
const store_pose = async () => {
  await axios({
    url: 'http://localhost:5000/store',
    method: 'post',
    data: {
      depth_1_x : depth_1.x.value,
      depth_1_y : depth_1.y.value,
      depth_1_z : depth_1.z.value,
      depth_1_roll : depth_1.roll.value,
      depth_1_pitch : depth_1.pitch.value,
      depth_1_yaw : depth_1.yaw.value,
      depth_2_x : depth_2.x.value,
      depth_2_y : depth_2.y.value,
      depth_2_z : depth_2.z.value,
      depth_2_roll : depth_2.roll.value,
      depth_2_pitch : depth_2.pitch.value,
      depth_2_yaw : depth_2.yaw.value,
      depth_3_x : depth_3.x.value,
      depth_3_y : depth_3.y.value,
      depth_3_z : depth_3.z.value,
      depth_3_roll : depth_3.roll.value,
      depth_3_pitch : depth_3.pitch.value,
      depth_3_yaw : depth_3.yaw.value,
      lidar_1_x : lidar_1.x.value,
      lidar_1_y : lidar_1.y.value,
      lidar_1_z : lidar_1.z.value,
      lidar_1_roll : lidar_1.roll.value,
      lidar_1_pitch : lidar_1.pitch.value,
      lidar_1_yaw : lidar_1.yaw.value,
      lidar_2_x : lidar_2.x.value,
      lidar_2_y : lidar_2.y.value,
      lidar_2_z : lidar_2.z.value,
      lidar_2_roll : lidar_2.roll.value,
      lidar_2_pitch : lidar_2.pitch.value,
      lidar_2_yaw : lidar_2.yaw.value,
      lidar_3_x : lidar_3.x.value,
      lidar_3_y : lidar_3.y.value,
      lidar_3_z : lidar_3.z.value,
      lidar_3_roll : lidar_3.roll.value,
      lidar_3_pitch : lidar_3.pitch.value,
      lidar_3_yaw : lidar_3.yaw.value,
      camera_1_x : camera_1.x.value,
      camera_1_y : camera_1.y.value,
      camera_1_z : camera_1.z.value,
      camera_1_roll : camera_1.roll.value,
      camera_1_pitch : camera_1.pitch.value,
      camera_1_yaw : camera_1.yaw.value,
    }
  });
};

const all_lidar_reference = async () => {
  await axios({
    url: 'http://localhost:5000/all_lidar_reference',
    data: {
      // TODO : None
    }
  });
};

const lidar_1_current = async () => {
  await axios({
    url: 'http://localhost:5000/lidar_1_current',
    data: {
      // TODO : None
    }
  });
};

const lidar_2_current = async () => {
  await axios({
    url: 'http://localhost:5000/lidar_2_current',
    data: {
      // TODO : None
    }
  });
};

const lidar_3_current = async () => {
  await axios({
    url: 'http://localhost:5000/lidar_3_current',
    data: {
      // TODO : None
    }
  });
};

const tf_listener = new ROSLIB.Topic({
  ros: ros,
  name: '/tf',
  messageType: 'tf2_msgs/TFMessage'
});

tf_listener.subscribe((message) => {
  if (message.transforms[0].child_frame_id === '/camera_01_tf') {
    camera_1.x.value = message.transforms[0].transform.translation.x.toString().substring(0, 6);
    camera_1.y.value = message.transforms[0].transform.translation.y.toString().substring(0, 6);
    camera_1.z.value = message.transforms[0].transform.translation.z.toString().substring(0, 6);
    camera_1.roll.value = message.transforms[0].transform.rotation.x.toString().substring(0, 6);
    camera_1.pitch.value = message.transforms[0].transform.rotation.y.toString().substring(0, 6);
    camera_1.yaw.value = message.transforms[0].transform.rotation.z.toString().substring(0, 6);
  }
  if (message.transforms[0].child_frame_id === '/depth_01_tf') {
    depth_1.x.value = message.transforms[0].transform.translation.x.toString().substring(0, 6);
    depth_1.y.value = message.transforms[0].transform.translation.y.toString().substring(0, 6);
    depth_1.z.value = message.transforms[0].transform.translation.z.toString().substring(0, 6);
    depth_1.roll.value = message.transforms[0].transform.rotation.x.toString().substring(0, 6);
    depth_1.pitch.value = message.transforms[0].transform.rotation.y.toString().substring(0, 6);
    depth_1.yaw.value = message.transforms[0].transform.rotation.z.toString().substring(0, 6);
  }
  if (message.transforms[0].child_frame_id === '/depth_02_tf') {
    depth_2.x.value = message.transforms[0].transform.translation.x.toString().substring(0, 6);
    depth_2.y.value = message.transforms[0].transform.translation.y.toString().substring(0, 6);
    depth_2.z.value = message.transforms[0].transform.translation.z.toString().substring(0, 6);
    depth_2.roll.value = message.transforms[0].transform.rotation.x.toString().substring(0, 6);
    depth_2.pitch.value = message.transforms[0].transform.rotation.y.toString().substring(0, 6);
    depth_2.yaw.value = message.transforms[0].transform.rotation.z.toString().substring(0, 6);
  }
  if (message.transforms[0].child_frame_id === '/depth_03_tf') {
    depth_3.x.value = message.transforms[0].transform.translation.x.toString().substring(0, 6);
    depth_3.y.value = message.transforms[0].transform.translation.y.toString().substring(0, 6);
    depth_3.z.value = message.transforms[0].transform.translation.z.toString().substring(0, 6);
    depth_3.roll.value = message.transforms[0].transform.rotation.x.toString().substring(0, 6);
    depth_3.pitch.value = message.transforms[0].transform.rotation.y.toString().substring(0, 6);
    depth_3.yaw.value = message.transforms[0].transform.rotation.z.toString().substring(0, 6);
  }
  if (message.transforms[0].child_frame_id === '/lidar_01_tf') {
    lidar_1.x.value = message.transforms[0].transform.translation.x.toString().substring(0, 6);
    lidar_1.y.value = message.transforms[0].transform.translation.y.toString().substring(0, 6);
    // [INVALID] lidar_1.z.value = message.transforms[0].transform.translation.z.toString().substring(0, 6);
    // [INVALID] lidar_1.roll.value = message.transforms[0].transform.rotation.x.toString().substring(0, 6);
    // [INVALID] lidar_1.pitch.value = message.transforms[0].transform.rotation.y.toString().substring(0, 6);
    lidar_1.yaw.value = message.transforms[0].transform.rotation.z.toString().substring(0, 6);
  }
  if (message.transforms[0].child_frame_id === '/lidar_02_tf') {
    lidar_2.x.value = message.transforms[0].transform.translation.x.toString().substring(0, 6);
    lidar_2.y.value = message.transforms[0].transform.translation.y.toString().substring(0, 6);
    // [INVALID] lidar_2.z.value = message.transforms[0].transform.translation.z.toString().substring(0, 6);
    // [INVALID] lidar_2.roll.value = message.transforms[0].transform.rotation.x.toString().substring(0, 6);
    // [INVALID] lidar_2.pitch.value = message.transforms[0].transform.rotation.y.toString().substring(0, 6);
    lidar_2.yaw.value = message.transforms[0].transform.rotation.z.toString().substring(0, 6);
  }
  if (message.transforms[0].child_frame_id === '/lidar_03_tf') {
    lidar_3.x.value = message.transforms[0].transform.translation.x.toString().substring(0, 6);
    lidar_3.y.value = message.transforms[0].transform.translation.y.toString().substring(0, 6);
    // [INVALID] lidar_3.z.value = message.transforms[0].transform.translation.z.toString().substring(0, 6);
    // [INVALID] lidar_3.roll.value = message.transforms[0].transform.rotation.x.toString().substring(0, 6);
    // [INVALID] lidar_3.pitch.value = message.transforms[0].transform.rotation.y.toString().substring(0, 6);
    lidar_3.yaw.value = message.transforms[0].transform.rotation.z.toString().substring(0, 6);
  }
});
</script>

<style scoped>
body {
  background-color: #444 !important;
  background-size: cover !important;
  overflow: scroll !important;
}
h2, h5, p {
  color: #f2f2f2 !important;
}
.bootstrap-select.btn-group .dropdown-menu li a:focus {
  border: 0;
  outline: none !important;
}
.bordered {
  background-color: #fff;
  padding: 15px;
  border: 1px solid #ccc;
  border-radius: .6rem;
}
.v-mar {
  margin: 15px 0;
}
.no-top {
  margin-top: 0;
}
.container {
  margin-bottom: 10rem;
}
label {
  font-weight: normal;
}
</style>