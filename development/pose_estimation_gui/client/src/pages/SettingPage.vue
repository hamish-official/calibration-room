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
              <input type="radio" name='rgb_active' checked><i class="fa fa-circle-o fa-2x"></i><i class="fa fa-check-circle-o fa-2x"></i><span> 활성화</span>
            </label>
            <label class="btn">
              <input type="radio" name='rgb_active'><i class="fa fa-circle-o fa-2x"></i><i class="fa fa-check-circle-o fa-2x"></i><span> 비활성화</span>
            </label>
          </div>
        </div>
      </div>

      <hr>
      RGB-D Camera:
      <br>
      <div class="btn-group btn-group" data-toggle="buttons">
        <label class="btn active">
          <input type="checkbox" name='depth1' checked><i class="fa fa-square-o fa-2x"></i><i class="fa fa-check-square-o fa-2x"></i><span> "/depth1"</span>
        </label>
        <label class="btn">
          <input type="checkbox" name='depth2'><i class="fa fa-square-o fa-2x"></i><i class="fa fa-check-square-o fa-2x"></i><span> "/depth2"</span>
        </label>
        <label class="btn">
          <input type="checkbox" name='depth3'><i class="fa fa-square-o fa-2x"></i><i class="fa fa-check-square-o fa-2x"></i><span> "/depth3"</span>
        </label>
      </div>

      <hr>
      2D LiDAR:
      <br>
      <div class="btn-group btn-group" data-toggle="buttons">
        <label class="btn active">
          <input type="checkbox" name='scan1' checked><i class="fa fa-square-o fa-2x"></i><i class="fa fa-check-square-o fa-2x"></i><span> "/scan1"</span>
        </label>
        <label class="btn">
          <input type="checkbox" name='scan2' checked><i class="fa fa-square-o fa-2x"></i><i class="fa fa-check-square-o fa-2x"></i><span> "/scan2"</span>
        </label>
        <label class="btn">
          <input type="checkbox" name='scan3'><i class="fa fa-square-o fa-2x"></i><i class="fa fa-check-square-o fa-2x"></i><span> "/scan3"</span>
        </label>
      </div>

      <br/>
      <div class="btn-group btn-group mt-5" data-toggle="buttons">
        <button class="btn btn-dark p-2"> 기본값 복원 </button>
        <button class="btn btn-primary p-2"> 설정값 저장 </button>
      </div>
    </div>
  </div>
</template>

<style>
label input[type="radio"] ~ i.fa.fa-circle-o{
    color: #c8c8c8;    display: inline;
}
label input[type="radio"] ~ i.fa.fa-dot-circle-o{
    display: none;
}
label input[type="radio"]:checked ~ i.fa.fa-circle-o{
    display: none;
}
label input[type="radio"]:checked ~ i.fa.fa-dot-circle-o{
    color: #7AA3CC;    display: inline;
}
label:hover input[type="radio"] ~ i.fa {
color: #7AA3CC;
}

label input[type="checkbox"] ~ i.fa.fa-square-o{
    color: #c8c8c8;    display: inline;
}
label input[type="checkbox"] ~ i.fa.fa-check-square-o{
    display: none;
}
label input[type="checkbox"]:checked ~ i.fa.fa-square-o{
    display: none;
}
label input[type="checkbox"]:checked ~ i.fa.fa-check-square-o{
    color: #7AA3CC;    display: inline;
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