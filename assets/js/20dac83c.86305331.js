"use strict";(self.webpackChunklightning_docs=self.webpackChunklightning_docs||[]).push([[2139],{8134:(e,i,o)=>{o.r(i),o.d(i,{assets:()=>a,contentTitle:()=>s,default:()=>h,frontMatter:()=>t,metadata:()=>l,toc:()=>c});var n=o(4848),r=o(8453);const t={sidebar_label:"Using Trapezoidal profilers",sidebar_position:7},s="How to use Trapezoidal profilers?",l={id:"Tutorials/Using_Trapezoidal_profilers",title:"How to use Trapezoidal profilers?",description:"Introduction",source:"@site/docs/Tutorials/Using_Trapezoidal_profilers.md",sourceDirName:"Tutorials",slug:"/Tutorials/Using_Trapezoidal_profilers",permalink:"/Lightninglib/docs/Tutorials/Using_Trapezoidal_profilers",draft:!1,unlisted:!1,editUrl:"https://github.com/HectorAlonso18/Lightninglib/tree/main/docs/Tutorials/Using_Trapezoidal_profilers.md",tags:[],version:"current",sidebarPosition:7,frontMatter:{sidebar_label:"Using Trapezoidal profilers",sidebar_position:7},sidebar:"tutorialSidebar",previous:{title:"How to create a FeedForward",permalink:"/Lightninglib/docs/Tutorials/How_to_create_Feed_Forward"},next:{title:"Using Paths",permalink:"/Lightninglib/docs/Tutorials/Using_Paths"}},a={},c=[{value:"Introduction",id:"introduction",level:2},{value:"Creating a Trapezoidal Profile",id:"creating-a-trapezoidal-profile",level:2},{value:"Setting the target",id:"setting-the-target",level:2},{value:"Moving with Trapezoidal Profile",id:"moving-with-trapezoidal-profile",level:2},{value:"Reusing a created profile",id:"reusing-a-created-profile",level:2},{value:"Printing velocities",id:"printing-velocities",level:2},{value:"Examples",id:"examples",level:2},{value:"Using profiles",id:"using-profiles",level:3},{value:"You finished the tutorial! \ud83c\udf89",id:"you-finished-the-tutorial-",level:2}];function d(e){const i={a:"a",admonition:"admonition",code:"code",h1:"h1",h2:"h2",h3:"h3",hr:"hr",img:"img",li:"li",ol:"ol",p:"p",pre:"pre",strong:"strong",...(0,r.R)(),...e.components};return(0,n.jsxs)(n.Fragment,{children:[(0,n.jsx)(i.h1,{id:"how-to-use-trapezoidal-profilers",children:"How to use Trapezoidal profilers?"}),"\n",(0,n.jsx)(i.h2,{id:"introduction",children:"Introduction"}),"\n",(0,n.jsx)(i.p,{children:"A trapezoidal profile is a type of motion control trajectory. This method is commonly used in robotics and automation to ensure smooth and controlled movements, minimizing sudden jerks and mechanical stress on the system."}),"\n",(0,n.jsx)(i.p,{children:"The trapezoidal profile has three distinct phases:"}),"\n",(0,n.jsxs)(i.ol,{children:["\n",(0,n.jsxs)(i.li,{children:[(0,n.jsx)(i.strong,{children:"Acceleration phase"}),": In this phase, there is a positive change in velocity."]}),"\n",(0,n.jsxs)(i.li,{children:[(0,n.jsx)(i.strong,{children:"Constant velocity phase"}),": The velocity remains constant, resulting in zero acceleration."]}),"\n",(0,n.jsxs)(i.li,{children:[(0,n.jsx)(i.strong,{children:"Deceleration phase"}),": The velocity decreases, resulting in deceleration until the system comes to a stop.\r\n",(0,n.jsx)(i.img,{alt:"perfil",src:o(3765).A+"",width:"295",height:"336"})]}),"\n"]}),"\n",(0,n.jsxs)(i.p,{children:["Image from taken from",(0,n.jsx)(i.a,{href:"https://www.pmdcorp.com/resources/type/articles/get/mathematics-of-motion-control-profiles-article",children:"Mathematics of Motion Control Profiles."})]}),"\n",(0,n.jsxs)(i.p,{children:["With ",(0,n.jsx)(i.code,{children:"Lightning"})," you are able to create trapezoidal profilers, which provide good performance when traveling distances."]}),"\n",(0,n.jsx)(i.hr,{}),"\n",(0,n.jsx)(i.h2,{id:"creating-a-trapezoidal-profile",children:"Creating a Trapezoidal Profile"}),"\n",(0,n.jsxs)(i.p,{children:["You can create a trapezoidal profile using the ",(0,n.jsx)(i.code,{children:"TrapezoidalProfile"})," Class."]}),"\n",(0,n.jsxs)(i.p,{children:["Check the ",(0,n.jsx)(i.a,{href:"/docs/Documentation/Trapezoidal",children:"Trapezoidal Profile Documentation"})," for more information."]}),"\n",(0,n.jsx)(i.p,{children:"But, before creating our profile, we need to determined the maximum velocity and the maximum acceleration for the profile."}),"\n",(0,n.jsx)(i.p,{children:"The maximum velocity and acceleration doesn\xb4t need to be the maximum achievable. For example, if you want to create a slower profile, you can set the maximum velocity and maximum acceleration to the half of your robot\xb4s maximum velocity and maximum acceleration."}),"\n",(0,n.jsx)(i.admonition,{type:"warning",children:(0,n.jsxs)(i.p,{children:["The velocity units must be in ",(0,n.jsx)(i.strong,{children:"(inches/seconds)"})," and the acceleration units in ",(0,n.jsxs)(i.strong,{children:["(inches/seconds",(0,n.jsx)("sup",{children:"2"}),")"]})," Otherwise, the code will not work as expected."]})}),"\n",(0,n.jsx)(i.p,{children:"Once you have determinated the maximum velocity and maximum acceleration, you are ready to create your profile."}),"\n",(0,n.jsx)(i.pre,{children:(0,n.jsx)(i.code,{className:"language-cpp",metastring:'title="main.cpp"',children:"void autonomous(){\r\n    lightning::TrapezoidalProfile profile (5,1); //5 inches/second, 1 inches/second^2 \r\n}\n"})}),"\n",(0,n.jsx)(i.hr,{}),"\n",(0,n.jsx)(i.h2,{id:"setting-the-target",children:"Setting the target"}),"\n",(0,n.jsx)(i.p,{children:"It\xb4s time to set profile\xb4s target."}),"\n",(0,n.jsxs)(i.p,{children:["For example, if you want that your robot travel 30 ",(0,n.jsx)(i.strong,{children:"inches"})," using the profile you already created, you need\r\nto update your profile."]}),"\n",(0,n.jsx)(i.pre,{children:(0,n.jsx)(i.code,{className:"language-cpp",metastring:'title="main.cpp"',children:"void autonomous(){\r\n    lightning::TrapezoidalProfile profile (5,1); //5 inches/second, 1 inches/second^2 \r\n    profile.update(30); //Updated for 30 inches. \r\n}\n"})}),"\n",(0,n.jsxs)(i.p,{children:["In this way, the profile will calculate the desired velocities for your robot to travel 30 ",(0,n.jsx)(i.strong,{children:"inches"}),"."]}),"\n",(0,n.jsx)(i.hr,{}),"\n",(0,n.jsx)(i.h2,{id:"moving-with-trapezoidal-profile",children:"Moving with Trapezoidal Profile"}),"\n",(0,n.jsx)(i.p,{children:"Finally, you just need to instruct your robot to follow the profile."}),"\n",(0,n.jsx)(i.pre,{children:(0,n.jsx)(i.code,{className:"language-cpp",metastring:'{4} title="main.cpp"',children:"void autonomous(){\r\n    lightning::TrapezoidalProfile profile (5,1); //5 inches/second, 1 inches/second^2 \r\n    profile.update(30); //Updated for 30 inches. \r\n    my_chassis.move_with_motion_profile(profile); //your robot would travel 30 inches\r\n}\n"})}),"\n",(0,n.jsx)(i.hr,{}),"\n",(0,n.jsx)(i.h2,{id:"reusing-a-created-profile",children:"Reusing a created profile"}),"\n",(0,n.jsx)(i.p,{children:"You can set different targets to the same profile using the reset() method before setting a new target. This allows you to set multiple distance targets for the same profile without creating a new one."}),"\n",(0,n.jsx)(i.pre,{children:(0,n.jsx)(i.code,{className:"language-cpp",metastring:'{5,8}  title="main.cpp"',children:"void autonomous(){\r\n    lightning::TrapezoidalProfile profile (5,1); //5 inches/second, 1 inches/second^2 \r\n    profile.update(30); //Updated for 30 inches. \r\n    my_chassis.move_with_motion_profile(profile); //your robot would travel 30 inches\r\n    profile.reset(); \r\n    profile.update(60); //Updated for 60 inches. \r\n    my_chassis.move_with_motion_profile(profile); //your robot would travel 60 inches\r\n    profile.reset(); \r\n    profile.update(15); //Updated for 15 inches. \r\n    my_chassis.move_with_motion_profile(profile); //your robot would travel 15 inches\r\n}\n"})}),"\n",(0,n.jsx)(i.hr,{}),"\n",(0,n.jsx)(i.h2,{id:"printing-velocities",children:"Printing velocities"}),"\n",(0,n.jsxs)(i.p,{children:["You can print the velocities from any profile to the integrated terminal using the ",(0,n.jsx)(i.code,{children:"std::cout<<"})," operator."]}),"\n",(0,n.jsx)(i.admonition,{type:"warning",children:(0,n.jsxs)(i.p,{children:["You ",(0,n.jsx)(i.strong,{children:"must"})," use this operator after setting the target."]})}),"\n",(0,n.jsx)(i.pre,{children:(0,n.jsx)(i.code,{className:"language-cpp",metastring:'{6} title="main.cpp"',children:"void autonomous(){\r\n    lightning::TrapezoidalProfile profile (5,1); //5 inches/second, 1 inches/second^2 \r\n\r\n    profile.update(30); //Updated for 30 inches. \r\n    \r\n    std::cout<<profile; //Print profile velocities. \r\n}\n"})}),"\n",(0,n.jsx)(i.hr,{}),"\n",(0,n.jsx)(i.h2,{id:"examples",children:"Examples"}),"\n",(0,n.jsx)(i.h3,{id:"using-profiles",children:"Using profiles"}),"\n",(0,n.jsx)(i.pre,{children:(0,n.jsx)(i.code,{className:"language-cpp",metastring:'title="main.cpp"',children:"void autonomous(){\r\n    lightning::TrapezoidalProfile profile (5,1); //5 inches/second, 1 inches/second^2 \r\n    lightning::TrapezoidalProfile high_profile (10,2); //10 inches/second, 2 inches/second^2 \r\n    lightning::TrapezoidalProfile low_profile(2.5,1); //2.5 inches/second, 1 inches/second^2 \r\n\r\n    profile.update(30); //Updated for 30 inches. \r\n    //your robot would travel 30 inches. \r\n    my_chassis.move_with_motion_profile(profile); \r\n    \r\n    high_profile.update(24); //Updated for 24 inches.\r\n    //your robot would travel 24 inches, using a fasted profile\r\n    my_chassis.move_with_motion_profile(high_profile); \r\n   \r\n\r\n    low_profile.update(45); //Updated for 45 inches. \r\n    //your robot would travel 45 inches, using a slower profile\r\n    my_chassis.move_with_motion_profile(profile); \r\n}\n"})}),"\n",(0,n.jsx)(i.hr,{}),"\n",(0,n.jsx)(i.h2,{id:"you-finished-the-tutorial-",children:"You finished the tutorial! \ud83c\udf89"}),"\n",(0,n.jsx)(i.p,{children:"You finished the tutorial! Now you can start using trapezoidal profiles in your code."}),"\n",(0,n.jsxs)(i.p,{children:["For more information check the ",(0,n.jsx)(i.a,{href:"/docs/Documentation/Trapezoidal",children:"TrapezoidalProfile Documentation."})]}),"\n",(0,n.jsx)(i.hr,{})]})}function h(e={}){const{wrapper:i}={...(0,r.R)(),...e.components};return i?(0,n.jsx)(i,{...e,children:(0,n.jsx)(d,{...e})}):d(e)}},3765:(e,i,o)=>{o.d(i,{A:()=>n});const n=o.p+"assets/images/trapezoidal_profile-7ff5476648bdb6437650f50223ca3deb.jpg"},8453:(e,i,o)=>{o.d(i,{R:()=>s,x:()=>l});var n=o(6540);const r={},t=n.createContext(r);function s(e){const i=n.useContext(t);return n.useMemo((function(){return"function"==typeof e?e(i):{...i,...e}}),[i,e])}function l(e){let i;return i=e.disableParentContext?"function"==typeof e.components?e.components(r):e.components||r:s(e.components),n.createElement(t.Provider,{value:i},e.children)}}}]);