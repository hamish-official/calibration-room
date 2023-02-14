<template>
  <div class="card">

    <div class="container">
      <h4>센서 설정</h4>
      <div class="row">
        <div class="col-xs-12">
          <hr> RGB Camera:
          <br>
          <div class="btn-group" data-toggle="buttons">
            <label class="btn active">
              <input type="radio" name='rgb_active' :checked="camera_activate" @click="() => {camera_activate = true}"><i class="fa fa-circle-o fa-2x"></i><i class="fa fa-check-circle-o fa-2x"></i><span> 활성화</span>
            </label>
            <label class="btn">
              <input type="radio" name='rgb_active' :checked="!camera_activate" @click="() => {camera_activate = false}"><i class="fa fa-circle-o fa-2x"></i><i class="fa fa-check-circle-o fa-2x"></i><span> 비활성화</span>
            </label>
          </div>
        </div>
      </div>

      <hr>
      RGB-D Camera:
      <br>
      <div class="btn-group btn-group" data-toggle="buttons">
        <label class="btn active">
          <input type="checkbox" :checked="depth1_activate" @click="() => {depth1_activate = !(depth1_activate)}"><i class="fa fa-square-o fa-2x"></i><i class="fa fa-check-square-o fa-2x"></i><span> "/depth1"</span>
        </label>
        <label class="btn">
          <input type="checkbox" :checked="depth2_activate" @click="() => {depth2_activate = !(depth2_activate)}"><i class="fa fa-square-o fa-2x"></i><i class="fa fa-check-square-o fa-2x"></i><span> "/depth2"</span>
        </label>
        <label class="btn">
          <input type="checkbox" :checked="depth3_activate" @click="() => {depth3_activate = !(depth3_activate)}"><i class="fa fa-square-o fa-2x"></i><i class="fa fa-check-square-o fa-2x"></i><span> "/depth3"</span>
        </label>
      </div>

      <hr>
      2D LiDAR:
      <br>
      <div class="btn-group btn-group" data-toggle="buttons">
        <label class="btn active">
          <input type="checkbox" :checked="lidar1_activate" @click="() => {lidar1_activate = !(lidar1_activate)}"><i class="fa fa-square-o fa-2x"></i><i class="fa fa-check-square-o fa-2x"></i><span> "/scan1"</span>
        </label>
        <label class="btn">
          <input type="checkbox" :checked="lidar2_activate" @click="() => {lidar2_activate = !(lidar2_activate)}"><i class="fa fa-square-o fa-2x"></i><i class="fa fa-check-square-o fa-2x"></i><span> "/scan2"</span>
        </label>
        <label class="btn">
          <input type="checkbox" :checked="lidar3_activate" @click="() => {lidar3_activate = !(lidar3_activate)}"><i class="fa fa-square-o fa-2x"></i><i class="fa fa-check-square-o fa-2x"></i><span> "/scan3"</span>
        </label>
      </div>

      <br/>
      <div class="btn-group btn-group mt-5" data-toggle="buttons">
        <button class="btn btn-dark p-2 m-1" @click="default_settings"> &nbsp;&nbsp;기본값 복원&nbsp;&nbsp; </button>
        <button class="btn btn-primary p-2 m-1" @click="customized_settings"> &nbsp;&nbsp;설정값 저장&nbsp;&nbsp; </button>
      </div>
    </div>
  </div>
</template>

<script setup>
import { ref } from 'vue';
import axios from 'axios';

const camera_activate = ref(true);
const depth1_activate = ref(true);
const depth2_activate = ref(false);
const depth3_activate = ref(false);
const lidar1_activate = ref(true);
const lidar2_activate = ref(true);
const lidar3_activate = ref(false);

const cr_settings_json = async () => {
  let data = await axios({
    url: 'http://localhost:5000/get-cr-settings',
    method: 'get',
    data: {
      // TODO : None
    }
  });

  data = JSON.parse(data.data.data);
  camera_activate.value = data.camera_activate;
  depth1_activate.value = data.depth1_activate;
  depth2_activate.value = data.depth2_activate;
  depth3_activate.value = data.depth3_activate;
  lidar1_activate.value = data.lidar1_activate;
  lidar2_activate.value = data.lidar2_activate;
  lidar3_activate.value = data.lidar3_activate;
};

cr_settings_json();

const default_settings = async () => {

  camera_activate.value = true;
  depth1_activate.value = true;
  depth2_activate.value = false;
  depth3_activate.value = false;
  lidar1_activate.value = true;
  lidar2_activate.value = true;
  lidar3_activate.value = false;

  const settings_json = {
    "camera_activate": camera_activate.value,
    "depth1_activate": depth1_activate.value,
    "depth2_activate": depth2_activate.value,
    "depth3_activate": depth3_activate.value,
    "lidar1_activate": lidar1_activate.value,
    "lidar2_activate": lidar2_activate.value,
    "lidar3_activate": lidar3_activate.value
  };

  try {
    const data = await axios({
      url: 'http://localhost:5000/cr-settings',
      method: 'post',
      data: {
        settings: JSON.stringify(settings_json)
      }
    });

    alert('기본값으로 변경되었습니다.');
  }
  catch (err) {
    alert('오류가 발생했습니다. cr-settings.json 파일이 정상적으로 저장되었는지 확인하십시오.')
  }
};

const customized_settings = async () => {
  const settings_json = {
    "camera_activate": camera_activate.value,
    "depth1_activate": depth1_activate.value,
    "depth2_activate": depth2_activate.value,
    "depth3_activate": depth3_activate.value,
    "lidar1_activate": lidar1_activate.value,
    "lidar2_activate": lidar2_activate.value,
    "lidar3_activate": lidar3_activate.value
  };

  try {
    const data = await axios({
      url: 'http://localhost:5000/cr-settings',
      method: 'post',
      data: {
        settings: JSON.stringify(settings_json)
      }
    });

    alert('설정값으로 변경되었습니다.');
  }
  catch (err) {
    alert('오류가 발생했습니다. cr-settings.json 파일이 정상적으로 저장되었는지 확인하십시오.')
  }
};
</script>

<style>
label input[type="radio"] ~ i.fa.fa-circle-o{

  color: #c8c8c8;
  display: inline;
}
label input[type="radio"] ~ i.fa.fa-dot-circle-o{
  display: none;
}
label input[type="radio"]:checked ~ i.fa.fa-circle-o{
    display: none;
}
label input[type="radio"]:checked ~ i.fa.fa-dot-circle-o{
  color: #7AA3CC;
  display: inline;
}
label:hover input[type="radio"] ~ i.fa {
  color: #7AA3CC;
}

label input[type="checkbox"] ~ i.fa.fa-square-o{
  color: #c8c8c8;
  display: inline;
}
label input[type="checkbox"] ~ i.fa.fa-check-square-o{
  display: none;
}
label input[type="checkbox"]:checked ~ i.fa.fa-square-o{
  display: none;
}
label input[type="checkbox"]:checked ~ i.fa.fa-check-square-o{
  color: #7AA3CC;
  display: inline;
}
label:hover input[type="checkbox"] ~ i.fa {
  color: #7AA3CC;
}

div[data-toggle="buttons"] label.active{
  color: #7AA3CC;
}

div[data-toggle="buttons"] label {
  display: inline-block;
  padding: 6px 12px;
  margin-bottom: 0;
  font-size: 14px;
  font-weight: normal;
  line-height: 2em;
  text-align: left;
  white-space: nowrap;
  vertical-align: top;
  cursor: pointer;
  background-color: none;
  border: 0px solid 
  #c8c8c8;
  border-radius: 3px;
  color: #c8c8c8;
  -webkit-user-select: none;
  -moz-user-select: none;
  -ms-user-select: none;
  -o-user-select: none;
  user-select: none;
}

div[data-toggle="buttons"] label:hover {
  color: #7AA3CC;
}

div[data-toggle="buttons"] label:active, div[data-toggle="buttons"] label.active {
  -webkit-box-shadow: none;
  box-shadow: none;
}
</style>