import * as VueRouter from 'vue-router';
import Homepage from './pages/HomePage.vue';
import CalibrationPage from './pages/CalibrationPage.vue';
import HelpPage from './pages/HelpPage.vue';
import SettingPage from './pages/SettingPage.vue';
import ManipulationPage from './pages/ManipulationPage.vue';

const routes = [
  {
    path: '/',
    component: Homepage
  },
  {
    path: '/calibration',
    component: CalibrationPage
  },
  {
    path: '/help',
    component: HelpPage
  },
  {
    path: '/settings',
    component: SettingPage
  },
  {
    path: '/manipulations',
    component: ManipulationPage
  }
];

const router = VueRouter.createRouter({
  history: VueRouter.createWebHashHistory(), routes
});

export { router };