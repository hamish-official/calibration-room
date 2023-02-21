<template>
  <div class="row mt-3">
    <div id="carouselExampleCaptions" class="carousel slide" data-bs-ride="false">
      <div class="carousel-indicators">
        <button type="button" data-bs-target="#carouselExampleCaptions" data-bs-slide-to="0" class="active" aria-current="true" aria-label="Slide 1"></button>
        <button type="button" data-bs-target="#carouselExampleCaptions" data-bs-slide-to="1" aria-label="Slide 2"></button>
        <button type="button" data-bs-target="#carouselExampleCaptions" data-bs-slide-to="2" aria-label="Slide 3"></button>
      </div>
      <div class="carousel-inner">
        <div class="carousel-item active">
          <p>Depth 1</p>
          <div class="row">
            <div class="col-md-6">
              <div class="bordered" style="background-color: #444;">
                <img :src="depth_1_image.image_1.value" style="width: 100%; height: 100%" />
              </div>
            </div>
            <div class="col-md-6">
              <div class="bordered" style="background-color: #444;">
                <img :src="depth_1_image.image_2.value" style="width: 100%; height: 100%" />
              </div>
            </div>
            <div class="row" style="height:6em"></div>
          </div>
          <p>Depth 2</p>
          <div class="row">
            <div class="col-md-6">
              <div class="bordered" style="background-color: #444;">
                <img :src="depth_2_image.image_1.value" style="width: 100%; height: 100%" />
              </div>
            </div>
            <div class="col-md-6">
              <div class="bordered" style="background-color: #444;">
                <img :src="depth_2_image.image_2.value" style="width: 100%; height: 100%" />
              </div>
            </div>
            <div class="row" style="height:6em"></div>
          </div>
          <p>Depth 3</p>
          <div class="row">
            <div class="col-md-6">
              <div class="bordered" style="background-color: #444;">
                <img :src="depth_3_image.image_1.value" style="width: 100%; height: 100%" />
              </div>
            </div>
            <div class="col-md-6">
              <div class="bordered" style="background-color: #444;">
                <img :src="depth_3_image.image_2.value" style="width: 100%; height: 100%" />
              </div>
            </div>
            <div class="row" style="height:6em"></div>
          </div>
          <div class="carousel-caption d-none d-md-block">
            <h5>Depth</h5>
          </div>
        </div>

        <div class="carousel-item">
          <p>Lidar 1</p>
          <div class="row">
            <div class="col-md-6">
              <div class="bordered" style="background-color: #444;">
                <img :src="lidar_1_image.image_1.value" style="width: 100%; height: 100%" />
              </div>
            </div>
            <div class="col-md-6">
              <div class="bordered" style="background-color: #444;">
                <img :src="lidar_1_image.image_2.value" style="width: 100%; height: 100%" />
              </div>
            </div>
            <div class="row" style="height:6em"></div>
          </div>
          <p>Lidar 2</p>
          <div class="row">
            <div class="col-md-6">
              <div class="bordered" style="background-color: #444;">
                <img :src="lidar_2_image.image_1.value" style="width: 100%; height: 100%" />
              </div>
            </div>
            <div class="col-md-6">
              <div class="bordered" style="background-color: #444;">
                <img :src="lidar_2_image.image_2.value" style="width: 100%; height: 100%" />
              </div>
            </div>
            <div class="row" style="height:6em"></div>
          </div>
          <p>Lidar 3</p>
          <div class="row">
            <div class="col-md-6">
              <div class="bordered" style="background-color: #444;">
                <img :src="lidar_3_image.image_1.value" style="width: 100%; height: 100%" />
              </div>
            </div>
            <div class="col-md-6">
              <div class="bordered" style="background-color: #444;">
                <img :src="lidar_3_image.image_2.value" style="width: 100%; height: 100%" />
              </div>
            </div>
            <div class="row" style="height:6em"></div>
          </div>
          <div class="carousel-caption d-none d-md-block">
            <h5>Lidar</h5>
          </div>
        </div>

        <div class="carousel-item">
          <p>Camera 1</p>
          <div class="row">
            <div class="col-md-6">
              <div class="bordered" style="background-color: #444;">
                <img :src="camera_1_image.image_1.value" style="width: 100%; height: 100%" />
              </div>
            </div>
            <div class="col-md-6">
              <div class="bordered" style="background-color: #444;">
                <img :src="camera_1_image.image_2.value" style="width: 100%; height: 100%" />
              </div>
            </div>
            <div class="row" style="height:6em"></div>
          </div>
          <div class="carousel-caption d-none d-md-block">
            <h5>Camera 1</h5>
          </div>
        </div>
      </div>

      <button class="carousel-control-prev" type="button" data-bs-target="#carouselExampleCaptions" data-bs-slide="prev">
        <span class="carousel-control-prev-icon" aria-hidden="true"></span>
        <span class="visually-hidden">Previous</span>
      </button>
      <button class="carousel-control-next" type="button" data-bs-target="#carouselExampleCaptions" data-bs-slide="next">
        <span class="carousel-control-next-icon" aria-hidden="true"></span>
        <span class="visually-hidden">Next</span>
      </button>
    </div>
  </div>
</template>

<script setup>
import ROSLIB from 'roslib';
import { ref } from 'vue';

const props = defineProps({
  ros: ROSLIB.Ros
});

const depth_1_image = { image_1: ref(''), image_2: ref('') };
const depth_2_image = { image_1: ref(''), image_2: ref('') };
const depth_3_image = { image_1: ref(''), image_2: ref('') };
const camera_1_image = { image_1: ref(''), image_2: ref('') };
const lidar_1_image = { image_1: ref(''), image_2: ref('') };
const lidar_2_image = { image_1: ref(''), image_2: ref('') };
const lidar_3_image = { image_1: ref(''), image_2: ref('') };

const depth_1_image_1 = new ROSLIB.Topic({
  ros: props.ros,
  name: '/depth_01_image_01',
  messageType: 'sensor_msgs/CompressedImage'
});

depth_1_image_1.subscribe((message) => {
  depth_1_image.image_1.value = 'data:image/jpg;base64,' + message.data;
});

const depth_1_image_2 = new ROSLIB.Topic({
  ros: props.ros,
  name: '/depth_01_image_02',
  messageType: 'sensor_msgs/CompressedImage'
});

depth_1_image_2.subscribe((message) => {
  depth_1_image.image_2.value = 'data:image/jpg;base64,' + message.data;
});

const depth_2_image_1 = new ROSLIB.Topic({
  ros: props.ros,
  name: '/depth_02_image_01',
  messageType: 'sensor_msgs/CompressedImage'
});

depth_2_image_1.subscribe((message) => {
  depth_2_image.image_1.value = 'data:image/jpg;base64,' + message.data;
});

const depth_2_image_2 = new ROSLIB.Topic({
  ros: props.ros,
  name: '/depth_02_image_02',
  messageType: 'sensor_msgs/CompressedImage'
});

depth_2_image_2.subscribe((message) => {
  depth_2_image.image_2.value = 'data:image/jpg;base64,' + message.data;
});

const depth_3_image_1 = new ROSLIB.Topic({
  ros: props.ros,
  name: '/depth_03_image_01',
  messageType: 'sensor_msgs/CompressedImage'
});

depth_3_image_1.subscribe((message) => {
  depth_3_image.image_1.value = 'data:image/jpg;base64,' + message.data;
});

const depth_3_image_2 = new ROSLIB.Topic({
  ros: props.ros,
  name: '/depth_03_image_02',
  messageType: 'sensor_msgs/CompressedImage'
});

depth_3_image_2.subscribe((message) => {
  depth_3_image.image_2.value = 'data:image/jpg;base64,' + message.data;
});

const camera_1_image_1 = new ROSLIB.Topic({
  ros: props.ros,
  name: '/camera_01_image_01',
  messageType: 'sensor_msgs/CompressedImage'
});

camera_1_image_1.subscribe((message) => {
  camera_1_image.image_1.value = 'data:image/jpg;base64,' + message.data;
});

const camera_1_image_2 = new ROSLIB.Topic({
  ros: props.ros,
  name: '/camera_01_image_02',
  messageType: 'sensor_msgs/CompressedImage'
});

camera_1_image_2.subscribe((message) => {
  camera_1_image.image_2.value = 'data:image/jpg;base64,' + message.data;
});

const lidar_1_image_1 = new ROSLIB.Topic({
  ros: props.ros,
  name: '/lidar_01_image_01',
  messageType: 'sensor_msgs/CompressedImage'
});

lidar_1_image_1.subscribe((message) => {
  lidar_1_image.image_1.value = 'data:image/jpg;base64,' + message.data;
});

const lidar_1_image_2 = new ROSLIB.Topic({
  ros: props.ros,
  name: '/lidar_01_image_02',
  messageType: 'sensor_msgs/CompressedImage'
});

lidar_1_image_2.subscribe((message) => {
  lidar_1_image.image_2.value = 'data:image/jpg;base64,' + message.data;
});

const lidar_2_image_1 = new ROSLIB.Topic({
  ros: props.ros,
  name: '/lidar_02_image_01',
  messageType: 'sensor_msgs/CompressedImage'
});

lidar_2_image_1.subscribe((message) => {
  lidar_2_image.image_1.value = 'data:image/jpg;base64,' + message.data;
});

const lidar_2_image_2 = new ROSLIB.Topic({
  ros: props.ros,
  name: '/lidar_02_image_02',
  messageType: 'sensor_msgs/CompressedImage'
});

lidar_2_image_2.subscribe((message) => {
  lidar_2_image.image_2.value = 'data:image/jpg;base64,' + message.data;
});

const lidar_3_image_1 = new ROSLIB.Topic({
  ros: props.ros,
  name: '/lidar_03_image_01',
  messageType: 'sensor_msgs/CompressedImage'
});

lidar_3_image_1.subscribe((message) => {
  lidar_3_image.image_1.value = 'data:image/jpg;base64,' + message.data;
});

const lidar_3_image_2 = new ROSLIB.Topic({
  ros: props.ros,
  name: '/lidar_03_image_02',
  messageType: 'sensor_msgs/CompressedImage'
});

lidar_3_image_2.subscribe((message) => {
  lidar_3_image.image_2.value = 'data:image/jpg;base64,' + message.data;
});
</script>

<style scoped>
.bordered {
  background-color: #fff;
  padding: 10px;
  border: 2px solid #ccc;
  border-radius: .4rem;
}
</style>