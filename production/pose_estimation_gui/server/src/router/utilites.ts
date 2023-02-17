import { Router } from 'express';
import type { Request, Response } from 'express';
import fs from 'fs';
import { networkInterfaces } from 'os';

const router = Router();

router.post('/store', async (request: Request, response: Response) => {
  const {
    depth_x, depth_y, depth_z, depth_roll, depth_pitch, depth_yaw,
    front_lidar_x, front_lidar_y, front_lidar_z,
    front_lidar_roll, front_lidar_pitch, front_lidar_yaw,
    rear_lidar_x, rear_lidar_y, rear_lidar_z,
    rear_lidar_roll, rear_lidar_pitch, rear_lidar_yaw,
    camera_x, camera_y, camera_z, camera_roll, camera_pitch, camera_yaw
  } = request.body;

  const urdf =
    `<robot name="cona">\n`
    + `\n`
    + `\t<link name="base_link"/>\n`
    +	`\t<link name="laser1"/>\n`
    +	`\t<link name="laser2"/>\n`
    +	`\t<link name="laser3"/>\n`
    +	`\t<link name="laser_multi"/>\n`
    +	`\t<link name="camera_link"/>\n`
    + `\n`
    + `\t<joint name="robot2laser1" type="fixed">\n`
		+ `\t\t<parent link="base_link"/>\n`
    + `\t\t<child link="laser1"/>\n`
    + `\t\t<origin xyz="${front_lidar_x} ${front_lidar_y} ${front_lidar_z}" rpy="${front_lidar_roll} ${front_lidar_pitch} ${front_lidar_yaw}" />\n`
    + `\t</joint>\n`
    + `\n`
    + `\t<joint name="robot2laser2" type="fixed">\n`
    + `\t\t<parent link="base_link"/>\n`
    + `\t\t<child link="laser2"/>\n`
    + `\t\t<origin xyz="${rear_lidar_x} ${rear_lidar_y} ${rear_lidar_z}" rpy="${rear_lidar_roll} ${rear_lidar_pitch} ${rear_lidar_yaw}" />\n`
    + `\t</joint>\n`
    + `\n`
    + `\t<joint name="robot2laser3" type="fixed">\n`
    + `\t\t<parent link="base_link"/>\n`
    + `\t\t<child link="laser3"/>\n`
		+ `\t\t<origin xyz="0.0 0.0 0.0" rpy="0 0.0 0" />\n`
    + `\t</joint>\n`
    + `\n`
    + `\t<joint name="robot2laser_multi" type="fixed">\n`
    + `\t\t<parent link="base_link" />\n`
    + `\t\t<child link="laser_multi" />\n`
    + `\t\t<origin xyz="0 0 0" rpy="0 0 0" />\n`
    + `\t</joint>\n`
    + `\n`
    + `\t<joint name="robot2depth" type="fixed">\n`
    + `\t\t<parent link="base_link"/>\n`
    + `\t\t<child link="camera_link"/>\n`
    + `\t\t<origin xyz="${depth_x} ${depth_y} ${depth_z}" rpy="${depth_roll} ${depth_pitch} ${depth_yaw}" />\n`
    + `\t</joint>\n`
    + `\n`
    + `</robot>`;

    fs.writeFileSync('cona.urdf', urdf);

    console.log(`cona.urdf 가 성공적으로 생성되었습니다.`);
});

router.get('/get-ip', async (request: Request, response: Response) => {
  try {
    const nets = networkInterfaces();
    let ip = '';

    if (nets) {
      for (const attribute of Object.keys(nets)) {
        if ((nets[`${attribute}`] as any)[0].address.startsWith('192')) {
          ip = (nets[`${attribute}`] as any)[0].address;
        }
        if ((nets[`${attribute}`] as any)[1].address.startsWith('192')) {
          ip = (nets[`${attribute}`] as any)[1].address;
        }
      }
    }

    return response.status(200).json({
      ip: ip
    });
  }
  catch (err) {
    return response.status(500).json({
      data: null
    });
  }
});

router.get('/get-cr-settings', async (request: Request, response: Response) => {
  try {
    const data = fs.readFileSync('assets/cr-settings.json', 'utf-8');
    return response.status(200).json({
      data: data
    });
  }
  catch (err) {
    return response.status(500).json({
      data: null
    });
  }
});

router.post('/cr-settings', async (request: Request, response: Response) => {
  try {
    fs.writeFileSync('assets/cr-settings.json', request.body.settings);
    return response.status(200).json({
      data: true
    });
  }
  catch (err) {
    return response.status(500).json({
      data: false
    });
  }
});

export { router };