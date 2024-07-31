"use strict";(self.webpackChunklightning_docs=self.webpackChunklightning_docs||[]).push([[1506],{2157:(e,l,r)=>{r.r(l),r.d(l,{assets:()=>d,contentTitle:()=>o,default:()=>h,frontMatter:()=>s,metadata:()=>c,toc:()=>p});var t=r(4848),n=r(8453),a=r(1470),i=r(9365);const s={sidebar_label:"Trapezoidal Profile",sidebar_position:3},o="TrapezoidalProfile",c={id:"Documentation/Trapezoidal",title:"TrapezoidalProfile",description:"The velocity units must be in (inches/seconds) and the acceleration units in (inches/seconds2) Otherwise, the code will not work as expected.",source:"@site/docs/Documentation/Trapezoidal.md",sourceDirName:"Documentation",slug:"/Documentation/Trapezoidal",permalink:"/Lightninglib/docs/Documentation/Trapezoidal",draft:!1,unlisted:!1,editUrl:"https://github.com/HectorAlonso18/Lightninglib/tree/main/docs/Documentation/Trapezoidal.md",tags:[],version:"current",sidebarPosition:3,frontMatter:{sidebar_label:"Trapezoidal Profile",sidebar_position:3},sidebar:"tutorialSidebar",previous:{title:"Feed Forward",permalink:"/Lightninglib/docs/Documentation/Feed_Forward"},next:{title:"Odom Tracker",permalink:"/Lightninglib/docs/Documentation/Odom_tracker"}},d={},p=[{value:"Constructor",id:"constructor",level:2},{value:"TrapezoidalProfile()",id:"trapezoidalprofile-1",level:3},{value:"Functions",id:"functions",level:2},{value:"update()",id:"update",level:3},{value:"reset()",id:"reset",level:3},{value:"is_ready()",id:"is_ready",level:3},{value:"Setters",id:"setters",level:2},{value:"set_parameters()",id:"set_parameters",level:3},{value:"set_max_velocity()",id:"set_max_velocity",level:3},{value:"set_max_acceleration()",id:"set_max_acceleration",level:3},{value:"Getters",id:"getters",level:2},{value:"get_velocity_at()",id:"get_velocity_at",level:3},{value:"get_max_velocity()",id:"get_max_velocity",level:3},{value:"get_max_acceleration()",id:"get_max_acceleration",level:3},{value:"get_accel_time()",id:"get_accel_time",level:3},{value:"get_accel_distance()",id:"get_accel_distance",level:3},{value:"get_desaccel_distance()",id:"get_desaccel_distance",level:3},{value:"get_velocity_constant_distance()",id:"get_velocity_constant_distance",level:3},{value:"get_time_to_arrived()",id:"get_time_to_arrived",level:3},{value:"get_size()",id:"get_size",level:3},{value:"get_velocities()",id:"get_velocities",level:3},{value:"Operators",id:"operators",level:2},{value:"<code>std::ostream &amp;operator &lt;&lt;</code>",id:"stdostream-operator-",level:3}];function u(e){const l={admonition:"admonition",code:"code",h1:"h1",h2:"h2",h3:"h3",hr:"hr",p:"p",pre:"pre",strong:"strong",table:"table",tbody:"tbody",td:"td",th:"th",thead:"thead",tr:"tr",...(0,n.R)(),...e.components};return(0,t.jsxs)(t.Fragment,{children:[(0,t.jsx)(l.h1,{id:"trapezoidalprofile",children:"TrapezoidalProfile"}),"\n",(0,t.jsx)(l.admonition,{type:"warning",children:(0,t.jsxs)(l.p,{children:["The velocity units must be in ",(0,t.jsx)(l.strong,{children:"(inches/seconds)"})," and the acceleration units in ",(0,t.jsxs)(l.strong,{children:["(inches/seconds",(0,t.jsx)("sup",{children:"2"}),")"]})," Otherwise, the code will not work as expected."]})}),"\n",(0,t.jsx)(l.h2,{id:"constructor",children:"Constructor"}),"\n",(0,t.jsx)(l.h3,{id:"trapezoidalprofile-1",children:"TrapezoidalProfile()"}),"\n",(0,t.jsx)(l.p,{children:"Trapezoidal profile constructor. Create a new trapezoidal profile."}),"\n",(0,t.jsxs)(a.A,{groupId:"trapezoidal_constructor",defaultValue:"proto",values:[{label:"Prototype",value:"proto"},{label:"Example",value:"example"}],children:[(0,t.jsx)(i.A,{value:"proto",children:(0,t.jsx)(l.pre,{children:(0,t.jsx)(l.code,{className:"language-cpp",children:"    TrapezoidalProfile(float max_velocity, float max_acceleration);\n"})})}),(0,t.jsx)(i.A,{value:"example",children:(0,t.jsx)(l.pre,{children:(0,t.jsx)(l.code,{className:"language-cpp",children:"void autonomous(){\r\n    lightning::TrapezoidalProfile profile (5,1); //5 inches/second, 1 inches/second^2 \r\n}\n"})})})]}),"\n",(0,t.jsxs)(l.table,{children:[(0,t.jsx)(l.thead,{children:(0,t.jsxs)(l.tr,{children:[(0,t.jsx)(l.th,{children:"Parameters"}),(0,t.jsx)(l.th,{})]})}),(0,t.jsxs)(l.tbody,{children:[(0,t.jsxs)(l.tr,{children:[(0,t.jsx)(l.td,{children:(0,t.jsx)(l.code,{children:"max_velocity"})}),(0,t.jsx)(l.td,{children:"What would be the maximum profile velocity?."})]}),(0,t.jsxs)(l.tr,{children:[(0,t.jsx)(l.td,{children:(0,t.jsx)(l.code,{children:"max_acceleration"})}),(0,t.jsx)(l.td,{children:"What would be the maximum profile accleration? ."})]})]})]}),"\n",(0,t.jsx)(l.hr,{}),"\n",(0,t.jsx)(l.h2,{id:"functions",children:"Functions"}),"\n",(0,t.jsx)(l.h3,{id:"update",children:"update()"}),"\n",(0,t.jsx)(l.p,{children:"Updates the trapezoidal profile giving the target and the sample time."}),"\n",(0,t.jsxs)(a.A,{groupId:"trapezoidal_functions_update",defaultValue:"proto",values:[{label:"Prototype",value:"proto"},{label:"Example",value:"example"}],children:[(0,t.jsx)(i.A,{value:"proto",children:(0,t.jsx)(l.pre,{children:(0,t.jsx)(l.code,{className:"language-cpp",children:"    void update(const float target, float sample_time_sec);\n"})})}),(0,t.jsx)(i.A,{value:"example",children:(0,t.jsx)(l.pre,{children:(0,t.jsx)(l.code,{className:"language-cpp",metastring:"{5}",children:"lightning::TrapezoidalProfile profile (5,1); //5 inches/second, 1 inches/second^2 \r\nvoid autonomous(){\r\n    //target= 48 inches.\r\n    //sample_time_sec = .01 seconds.\r\n    profile.update(48,.01); \r\n}\n"})})})]}),"\n",(0,t.jsxs)(l.table,{children:[(0,t.jsx)(l.thead,{children:(0,t.jsxs)(l.tr,{children:[(0,t.jsx)(l.th,{children:"Parameters"}),(0,t.jsx)(l.th,{})]})}),(0,t.jsxs)(l.tbody,{children:[(0,t.jsxs)(l.tr,{children:[(0,t.jsx)(l.td,{children:(0,t.jsx)(l.code,{children:"target"})}),(0,t.jsx)(l.td,{children:"How many distance you would travel in inches."})]}),(0,t.jsxs)(l.tr,{children:[(0,t.jsx)(l.td,{children:(0,t.jsx)(l.code,{children:"sample_time_sec"})}),(0,t.jsx)(l.td,{children:"The update rate in secconds. ."})]})]})]}),"\n",(0,t.jsx)(l.hr,{}),"\n",(0,t.jsx)(l.h3,{id:"reset",children:"reset()"}),"\n",(0,t.jsx)(l.p,{children:"Resets the trapezoidal profile."}),"\n",(0,t.jsx)(l.admonition,{type:"note",children:(0,t.jsx)(l.p,{children:"The function erases and clean all the profile."})}),"\n",(0,t.jsxs)(a.A,{groupId:"trapezoidal_functions_reset",defaultValue:"proto",values:[{label:"Prototype",value:"proto"},{label:"Example",value:"example"}],children:[(0,t.jsx)(i.A,{value:"proto",children:(0,t.jsx)(l.pre,{children:(0,t.jsx)(l.code,{className:"language-cpp",children:"    void reset();\n"})})}),(0,t.jsx)(i.A,{value:"example",children:(0,t.jsx)(l.pre,{children:(0,t.jsx)(l.code,{className:"language-cpp",metastring:"{10}",children:"void autonomous(){\r\n    lightning::TrapezoidalProfile profile (5,1); //5 inches/second, 1 inches/second^2 \r\n    profile.update(48,.01);  // 48 inches , .01 sec\r\n\r\n    /*\r\n    USING THE PROFILE during autonomous \r\n    */\r\n\r\n    //When we finish using the profile\r\n    profile.reset();\r\n}\r\n\n"})})})]}),"\n",(0,t.jsx)(l.hr,{}),"\n",(0,t.jsx)(l.h3,{id:"is_ready",children:"is_ready()"}),"\n",(0,t.jsx)(l.p,{children:"Checks if the profile its ready to use."}),"\n",(0,t.jsxs)(a.A,{groupId:"trapezoidal_functions_is_ready",defaultValue:"proto",values:[{label:"Prototype",value:"proto"},{label:"Example",value:"example"}],children:[(0,t.jsx)(i.A,{value:"proto",children:(0,t.jsx)(l.pre,{children:(0,t.jsx)(l.code,{className:"language-cpp",children:"    bool is_ready() const;\n"})})}),(0,t.jsx)(i.A,{value:"example",children:(0,t.jsx)(l.pre,{children:(0,t.jsx)(l.code,{className:"language-cpp",metastring:"{5}",children:"void autonomous(){\r\n    lightning::TrapezoidalProfile profile (5,1); //5 inches/second, 1 inches/second^2\r\n    profile.update(48,.01); // 48 inches , .01 sec\r\n    \r\n    if(profile.is_ready()){\r\n    /*\r\n    MAKE THINGS \r\n    */\r\n    } \r\n}\n"})})})]}),"\n",(0,t.jsx)(l.hr,{}),"\n",(0,t.jsx)(l.h2,{id:"setters",children:"Setters"}),"\n",(0,t.jsx)(l.h3,{id:"set_parameters",children:"set_parameters()"}),"\n",(0,t.jsx)(l.p,{children:"Sets the main parameters for the profile."}),"\n",(0,t.jsxs)(a.A,{groupId:"trapezoidal_setters_parameters",defaultValue:"proto",values:[{label:"Prototype",value:"proto"},{label:"Example",value:"example"}],children:[(0,t.jsx)(i.A,{value:"proto",children:(0,t.jsx)(l.pre,{children:(0,t.jsx)(l.code,{className:"language-cpp",children:"    void set_parameters(const float max_velocity, const float max_acceleration); \n"})})}),(0,t.jsx)(i.A,{value:"example",children:(0,t.jsx)(l.pre,{children:(0,t.jsx)(l.code,{className:"language-cpp",children:"lightning::TrapezoidalProfile profile (5,1); //5 inches/second, 1 inches/second^2 \r\nvoid autonomous(){\r\n    profile.set_parameters(10,2); //10 inches/second, 2 inches/second^2\r\n}\n"})})})]}),"\n",(0,t.jsxs)(l.table,{children:[(0,t.jsx)(l.thead,{children:(0,t.jsxs)(l.tr,{children:[(0,t.jsx)(l.th,{children:"Parameters"}),(0,t.jsx)(l.th,{})]})}),(0,t.jsxs)(l.tbody,{children:[(0,t.jsxs)(l.tr,{children:[(0,t.jsx)(l.td,{children:(0,t.jsx)(l.code,{children:"max_velocity"})}),(0,t.jsx)(l.td,{children:"What would be the maximum profile velocity?."})]}),(0,t.jsxs)(l.tr,{children:[(0,t.jsx)(l.td,{children:(0,t.jsx)(l.code,{children:"max_acceleration"})}),(0,t.jsx)(l.td,{children:"What would be the maximum profile accleration? ."})]})]})]}),"\n",(0,t.jsx)(l.hr,{}),"\n",(0,t.jsx)(l.h3,{id:"set_max_velocity",children:"set_max_velocity()"}),"\n",(0,t.jsx)(l.p,{children:"Sets the maximum profile velocity."}),"\n",(0,t.jsxs)(a.A,{groupId:"trapezoidal_setters_max_velocity",defaultValue:"proto",values:[{label:"Prototype",value:"proto"},{label:"Example",value:"example"}],children:[(0,t.jsx)(i.A,{value:"proto",children:(0,t.jsx)(l.pre,{children:(0,t.jsx)(l.code,{className:"language-cpp",children:"    void set_max_velocity(const float max_velocity);\n"})})}),(0,t.jsx)(i.A,{value:"example",children:(0,t.jsx)(l.pre,{children:(0,t.jsx)(l.code,{className:"language-cpp",children:"lightning::TrapezoidalProfile profile (5,1); //5 inches/second, 1 inches/second^2 \r\nvoid autonomous(){\r\n    profile.set_max_velocity(10); //5 inches/second \r\n}\n"})})})]}),"\n",(0,t.jsxs)(l.table,{children:[(0,t.jsx)(l.thead,{children:(0,t.jsxs)(l.tr,{children:[(0,t.jsx)(l.th,{children:"Parameters"}),(0,t.jsx)(l.th,{})]})}),(0,t.jsx)(l.tbody,{children:(0,t.jsxs)(l.tr,{children:[(0,t.jsx)(l.td,{children:(0,t.jsx)(l.code,{children:"max_velocity"})}),(0,t.jsx)(l.td,{children:"What would be the maximum profile velocity?."})]})})]}),"\n",(0,t.jsx)(l.hr,{}),"\n",(0,t.jsx)(l.h3,{id:"set_max_acceleration",children:"set_max_acceleration()"}),"\n",(0,t.jsx)(l.p,{children:"Sets the maximum profile acceleration."}),"\n",(0,t.jsxs)(a.A,{groupId:"trapezoidal_setters_max_acceleration",defaultValue:"proto",values:[{label:"Prototype",value:"proto"},{label:"Example",value:"example"}],children:[(0,t.jsx)(i.A,{value:"proto",children:(0,t.jsx)(l.pre,{children:(0,t.jsx)(l.code,{className:"language-cpp",children:"    void set_max_acceleration(const float max_acceleration);\r\n\n"})})}),(0,t.jsx)(i.A,{value:"example",children:(0,t.jsx)(l.pre,{children:(0,t.jsx)(l.code,{className:"language-cpp",metastring:"{4}",children:"lightning::TrapezoidalProfile profile (5,1); \r\nvoid autonomous(){\r\n    profile.set_max_velocity(10); //10 inches/second\r\n    profile.set_max_acceleration(2); //2 inches/second^2\r\n}\n"})})})]}),"\n",(0,t.jsxs)(l.table,{children:[(0,t.jsx)(l.thead,{children:(0,t.jsxs)(l.tr,{children:[(0,t.jsx)(l.th,{children:"Parameters"}),(0,t.jsx)(l.th,{})]})}),(0,t.jsx)(l.tbody,{children:(0,t.jsxs)(l.tr,{children:[(0,t.jsx)(l.td,{children:(0,t.jsx)(l.code,{children:"max_acceleration"})}),(0,t.jsx)(l.td,{children:"What would be the maximum profile accleration? ."})]})})]}),"\n",(0,t.jsx)(l.hr,{}),"\n",(0,t.jsx)(l.h2,{id:"getters",children:"Getters"}),"\n",(0,t.jsx)(l.h3,{id:"get_velocity_at",children:"get_velocity_at()"}),"\n",(0,t.jsx)(l.p,{children:"Gets the desired velocity giving a point."}),"\n",(0,t.jsxs)(a.A,{groupId:"trapezoidal_getters_velocity_at",defaultValue:"proto",values:[{label:"Prototype",value:"proto"},{label:"Example",value:"example"}],children:[(0,t.jsx)(i.A,{value:"proto",children:(0,t.jsx)(l.pre,{children:(0,t.jsx)(l.code,{className:"language-cpp",children:"    float get_velocity_at(int index) const;\r\n\n"})})}),(0,t.jsx)(i.A,{value:"example",children:(0,t.jsx)(l.pre,{children:(0,t.jsx)(l.code,{className:"language-cpp",children:"lightning::TrapezoidalProfile profile (5,1); \r\nvoid autonomous(){\r\n    profile.update(48,.01); // 48 inches , .01 sec\r\n\r\n    float velocity = profile.get_velocity_at(5) //getting the velocity at index 5. \r\n}\n"})})})]}),"\n",(0,t.jsxs)(l.table,{children:[(0,t.jsx)(l.thead,{children:(0,t.jsxs)(l.tr,{children:[(0,t.jsx)(l.th,{children:"Parameters"}),(0,t.jsx)(l.th,{})]})}),(0,t.jsx)(l.tbody,{children:(0,t.jsxs)(l.tr,{children:[(0,t.jsx)(l.td,{children:(0,t.jsx)(l.code,{children:"index"})}),(0,t.jsx)(l.td,{children:"Index the profile index."})]})})]}),"\n",(0,t.jsxs)(l.p,{children:[(0,t.jsx)(l.strong,{children:"Returns:"})," The desired velocity."]}),"\n",(0,t.jsx)(l.hr,{}),"\n",(0,t.jsx)(l.h3,{id:"get_max_velocity",children:"get_max_velocity()"}),"\n",(0,t.jsx)(l.p,{children:"Gets the maximum profile velocity."}),"\n",(0,t.jsxs)(a.A,{groupId:"trapezoidal_getters_max_velocity",defaultValue:"proto",values:[{label:"Prototype",value:"proto"},{label:"Example",value:"example"}],children:[(0,t.jsx)(i.A,{value:"proto",children:(0,t.jsx)(l.pre,{children:(0,t.jsx)(l.code,{className:"language-cpp",children:"    float get_max_velocity() const;\r\n\n"})})}),(0,t.jsx)(i.A,{value:"example",children:(0,t.jsx)(l.pre,{children:(0,t.jsx)(l.code,{className:"language-cpp",children:"lightning::TrapezoidalProfile profile (5,1); \r\nvoid autonomous(){\r\n    profile.update(48,.01); // 48 inches , .01 sec\r\n\r\n    float max_velocity = profile.get_max_velocity(); \r\n}\n"})})})]}),"\n",(0,t.jsxs)(l.p,{children:[(0,t.jsx)(l.strong,{children:"Returns:"})," The maximum velocity."]}),"\n",(0,t.jsx)(l.hr,{}),"\n",(0,t.jsx)(l.h3,{id:"get_max_acceleration",children:"get_max_acceleration()"}),"\n",(0,t.jsx)(l.p,{children:"Gets the maximum profile acceleration."}),"\n",(0,t.jsxs)(a.A,{groupId:"trapezoidal_getters_max_acceleration",defaultValue:"proto",values:[{label:"Prototype",value:"proto"},{label:"Example",value:"example"}],children:[(0,t.jsx)(i.A,{value:"proto",children:(0,t.jsx)(l.pre,{children:(0,t.jsx)(l.code,{className:"language-cpp",children:"    float get_max_acceleration() const;\r\n\n"})})}),(0,t.jsx)(i.A,{value:"example",children:(0,t.jsx)(l.pre,{children:(0,t.jsx)(l.code,{className:"language-cpp",children:"lightning::TrapezoidalProfile profile (5,1); \r\nvoid autonomous(){\r\n    profile.update(48,.01); // 48 inches , .01 sec\r\n\r\n    float max_acceleration = profile.get_max_acceleration(); \r\n}\n"})})})]}),"\n",(0,t.jsxs)(l.p,{children:[(0,t.jsx)(l.strong,{children:"Returns:"})," The maximum acceleration."]}),"\n",(0,t.jsx)(l.hr,{}),"\n",(0,t.jsx)(l.h3,{id:"get_accel_time",children:"get_accel_time()"}),"\n",(0,t.jsx)(l.p,{children:"Gets the acceleration time."}),"\n",(0,t.jsxs)(a.A,{groupId:"trapezoidal_getters_accel_time",defaultValue:"proto",values:[{label:"Prototype",value:"proto"},{label:"Example",value:"example"}],children:[(0,t.jsx)(i.A,{value:"proto",children:(0,t.jsx)(l.pre,{children:(0,t.jsx)(l.code,{className:"language-cpp",children:"    float get_accel_time() const;\r\n\n"})})}),(0,t.jsx)(i.A,{value:"example",children:(0,t.jsx)(l.pre,{children:(0,t.jsx)(l.code,{className:"language-cpp",children:"lightning::TrapezoidalProfile profile (5,1); \r\nvoid autonomous(){\r\n    profile.update(48,.01); // 48 inches , .01 sec\r\n\r\n    float accel_time = profile.get_accel_time(); \r\n}\n"})})})]}),"\n",(0,t.jsxs)(l.p,{children:[(0,t.jsx)(l.strong,{children:"Returns:"})," The acceleration time."]}),"\n",(0,t.jsx)(l.hr,{}),"\n",(0,t.jsx)(l.h3,{id:"get_accel_distance",children:"get_accel_distance()"}),"\n",(0,t.jsx)(l.p,{children:"Gets the acceleration distance (acceleration phase)."}),"\n",(0,t.jsxs)(a.A,{groupId:"trapezoidal_getters_accel_distance",defaultValue:"proto",values:[{label:"Prototype",value:"proto"},{label:"Example",value:"example"}],children:[(0,t.jsx)(i.A,{value:"proto",children:(0,t.jsx)(l.pre,{children:(0,t.jsx)(l.code,{className:"language-cpp",children:"    float get_accel_distance() const;\r\n\n"})})}),(0,t.jsx)(i.A,{value:"example",children:(0,t.jsx)(l.pre,{children:(0,t.jsx)(l.code,{className:"language-cpp",children:"lightning::TrapezoidalProfile profile (5,1); \r\nvoid autonomous(){\r\n    profile.update(48,.01); // 48 inches , .01 sec\r\n\r\n    float accel_distance = profile.get_accel_distance(); \r\n}\n"})})})]}),"\n",(0,t.jsxs)(l.p,{children:[(0,t.jsx)(l.strong,{children:"Returns:"}),"  The acceleration time."]}),"\n",(0,t.jsx)(l.hr,{}),"\n",(0,t.jsx)(l.h3,{id:"get_desaccel_distance",children:"get_desaccel_distance()"}),"\n",(0,t.jsx)(l.p,{children:"Gets the desacceleration distance (desacceleration phase)."}),"\n",(0,t.jsxs)(a.A,{groupId:"trapezoidal_getters_desaccel_distance",defaultValue:"proto",values:[{label:"Prototype",value:"proto"},{label:"Example",value:"example"}],children:[(0,t.jsx)(i.A,{value:"proto",children:(0,t.jsx)(l.pre,{children:(0,t.jsx)(l.code,{className:"language-cpp",children:"    float get_desaccel_distance() const;\r\n\n"})})}),(0,t.jsx)(i.A,{value:"example",children:(0,t.jsx)(l.pre,{children:(0,t.jsx)(l.code,{className:"language-cpp",children:"lightning::TrapezoidalProfile profile (5,1); \r\nvoid autonomous(){\r\n    profile.update(48,.01); // 48 inches , .01 sec\r\n\r\n    float desaccel_distance = profile.get_desaccel_distance();\r\n}\n"})})})]}),"\n",(0,t.jsxs)(l.p,{children:[(0,t.jsx)(l.strong,{children:"Returns:"})," Gets the desacceleration time."]}),"\n",(0,t.jsx)(l.hr,{}),"\n",(0,t.jsx)(l.h3,{id:"get_velocity_constant_distance",children:"get_velocity_constant_distance()"}),"\n",(0,t.jsx)(l.p,{children:"Gets the constant velocity distance (constant acceleration phase)."}),"\n",(0,t.jsxs)(a.A,{groupId:"trapezoidal_getters_velocity_constant_distance",defaultValue:"proto",values:[{label:"Prototype",value:"proto"},{label:"Example",value:"example"}],children:[(0,t.jsx)(i.A,{value:"proto",children:(0,t.jsx)(l.pre,{children:(0,t.jsx)(l.code,{className:"language-cpp",children:"    float get_velocity_constant_distance() const;\r\n\n"})})}),(0,t.jsx)(i.A,{value:"example",children:(0,t.jsx)(l.pre,{children:(0,t.jsx)(l.code,{className:"language-cpp",children:"lightning::TrapezoidalProfile profile (5,1); \r\nvoid autonomous(){\r\n    profile.update(48,.01); // 48 inches , .01 sec\r\n\r\n    float velocity_constant_distance = profile.get_velocity_constant_distance();\r\n}\n"})})})]}),"\n",(0,t.jsxs)(l.p,{children:[(0,t.jsx)(l.strong,{children:"Returns:"})," Gets the constant velocity distance."]}),"\n",(0,t.jsx)(l.hr,{}),"\n",(0,t.jsx)(l.h3,{id:"get_time_to_arrived",children:"get_time_to_arrived()"}),"\n",(0,t.jsx)(l.p,{children:"Gets the time to arrive."}),"\n",(0,t.jsxs)(a.A,{groupId:"trapezoidal_getters_time_to_arrived",defaultValue:"proto",values:[{label:"Prototype",value:"proto"},{label:"Example",value:"example"}],children:[(0,t.jsx)(i.A,{value:"proto",children:(0,t.jsx)(l.pre,{children:(0,t.jsx)(l.code,{className:"language-cpp",children:"    float get_time_to_arrived() const; \r\n\n"})})}),(0,t.jsx)(i.A,{value:"example",children:(0,t.jsx)(l.pre,{children:(0,t.jsx)(l.code,{className:"language-cpp",children:"lightning::TrapezoidalProfile profile (5,1); \r\nvoid autonomous(){\r\n    profile.update(48,.01); // 48 inches , .01 sec\r\n\r\n    float time_to_arrived = profile.get_time_to_arrived();  // in seconds\r\n}\n"})})})]}),"\n",(0,t.jsxs)(l.p,{children:[(0,t.jsx)(l.strong,{children:"Returns:"})," The time to arrive in seconds."]}),"\n",(0,t.jsx)(l.hr,{}),"\n",(0,t.jsx)(l.h3,{id:"get_size",children:"get_size()"}),"\n",(0,t.jsx)(l.p,{children:"Returns the profile size."}),"\n",(0,t.jsxs)(a.A,{groupId:"trapezoidal_getters_size",defaultValue:"proto",values:[{label:"Prototype",value:"proto"},{label:"Example",value:"example"}],children:[(0,t.jsx)(i.A,{value:"proto",children:(0,t.jsx)(l.pre,{children:(0,t.jsx)(l.code,{className:"language-cpp",children:"    std::size_t get_size() const; \r\n\n"})})}),(0,t.jsx)(i.A,{value:"example",children:(0,t.jsx)(l.pre,{children:(0,t.jsx)(l.code,{className:"language-cpp",children:"lightning::TrapezoidalProfile profile (5,1); \r\nvoid autonomous(){\r\n    profile.update(48,.01); // 48 inches , .01 sec\r\n\r\n    int profile_size = profile.get_size();\r\n}\n"})})})]}),"\n",(0,t.jsxs)(l.p,{children:[(0,t.jsx)(l.strong,{children:"Returns:"})," The current profile size."]}),"\n",(0,t.jsx)(l.hr,{}),"\n",(0,t.jsx)(l.h3,{id:"get_velocities",children:"get_velocities()"}),"\n",(0,t.jsx)(l.p,{children:"Return a vector with the desired velocities using the trapezoidal profile."}),"\n",(0,t.jsxs)(a.A,{groupId:"trapezoidal_getters_velocities",defaultValue:"proto",values:[{label:"Prototype",value:"proto"},{label:"Example",value:"example"}],children:[(0,t.jsx)(i.A,{value:"proto",children:(0,t.jsx)(l.pre,{children:(0,t.jsx)(l.code,{className:"language-cpp",children:"    std::vector<float> get_velocities() const;\r\n\n"})})}),(0,t.jsx)(i.A,{value:"example",children:(0,t.jsx)(l.pre,{children:(0,t.jsx)(l.code,{className:"language-cpp",children:"lightning::TrapezoidalProfile profile (5,1); \r\nvoid autonomous(){\r\n    profile.update(48,.01); // 48 inches , .01 sec\r\n    \r\n    //Saving the profile velocities to a new vector.\r\n    std::vector<float> profile_velocities = profile.get_velocities(); \r\n}\n"})})})]}),"\n",(0,t.jsxs)(l.p,{children:[(0,t.jsx)(l.strong,{children:"Returns:"})," Desired velocities vector."]}),"\n",(0,t.jsx)(l.hr,{}),"\n",(0,t.jsx)(l.h2,{id:"operators",children:"Operators"}),"\n",(0,t.jsx)(l.h3,{id:"stdostream-operator-",children:(0,t.jsx)(l.code,{children:"std::ostream &operator <<"})}),"\n",(0,t.jsxs)(l.p,{children:["Prints the  desired velocities of a ",(0,t.jsx)(l.code,{children:"TrapezoidalProfile"})," object in Integrated Terminal."]}),"\n",(0,t.jsxs)(a.A,{groupId:"trapezoidal_operator_<<",defaultValue:"proto",values:[{label:"Prototype",value:"proto"},{label:"Example",value:"example"}],children:[(0,t.jsx)(i.A,{value:"proto",children:(0,t.jsx)(l.pre,{children:(0,t.jsx)(l.code,{className:"language-cpp",children:"    std::ostream &operator<<(std::ostream &os,const TrapezoidalProfile &profile);\r\n\n"})})}),(0,t.jsx)(i.A,{value:"example",children:(0,t.jsx)(l.pre,{children:(0,t.jsx)(l.code,{className:"language-cpp",children:"lightning::TrapezoidalProfile profile (5,1); \r\nvoid autonomous(){\r\n    profile.update(48,.01); // 48 inches , .01 sec\r\n    \r\n    //Printing velocities\r\n    std::cout<<profile; \r\n}\n"})})})]}),"\n",(0,t.jsx)(l.hr,{})]})}function h(e={}){const{wrapper:l}={...(0,n.R)(),...e.components};return l?(0,t.jsx)(l,{...e,children:(0,t.jsx)(u,{...e})}):u(e)}},9365:(e,l,r)=>{r.d(l,{A:()=>i});r(6540);var t=r(4164);const n={tabItem:"tabItem_Ymn6"};var a=r(4848);function i(e){let{children:l,hidden:r,className:i}=e;return(0,a.jsx)("div",{role:"tabpanel",className:(0,t.A)(n.tabItem,i),hidden:r,children:l})}},1470:(e,l,r)=>{r.d(l,{A:()=>y});var t=r(6540),n=r(4164),a=r(3104),i=r(6347),s=r(205),o=r(7485),c=r(1682),d=r(679);function p(e){return t.Children.toArray(e).filter((e=>"\n"!==e)).map((e=>{if(!e||(0,t.isValidElement)(e)&&function(e){const{props:l}=e;return!!l&&"object"==typeof l&&"value"in l}(e))return e;throw new Error(`Docusaurus error: Bad <Tabs> child <${"string"==typeof e.type?e.type:e.type.name}>: all children of the <Tabs> component should be <TabItem>, and every <TabItem> should have a unique "value" prop.`)}))?.filter(Boolean)??[]}function u(e){const{values:l,children:r}=e;return(0,t.useMemo)((()=>{const e=l??function(e){return p(e).map((e=>{let{props:{value:l,label:r,attributes:t,default:n}}=e;return{value:l,label:r,attributes:t,default:n}}))}(r);return function(e){const l=(0,c.X)(e,((e,l)=>e.value===l.value));if(l.length>0)throw new Error(`Docusaurus error: Duplicate values "${l.map((e=>e.value)).join(", ")}" found in <Tabs>. Every value needs to be unique.`)}(e),e}),[l,r])}function h(e){let{value:l,tabValues:r}=e;return r.some((e=>e.value===l))}function x(e){let{queryString:l=!1,groupId:r}=e;const n=(0,i.W6)(),a=function(e){let{queryString:l=!1,groupId:r}=e;if("string"==typeof l)return l;if(!1===l)return null;if(!0===l&&!r)throw new Error('Docusaurus error: The <Tabs> component groupId prop is required if queryString=true, because this value is used as the search param name. You can also provide an explicit value such as queryString="my-search-param".');return r??null}({queryString:l,groupId:r});return[(0,o.aZ)(a),(0,t.useCallback)((e=>{if(!a)return;const l=new URLSearchParams(n.location.search);l.set(a,e),n.replace({...n.location,search:l.toString()})}),[a,n])]}function m(e){const{defaultValue:l,queryString:r=!1,groupId:n}=e,a=u(e),[i,o]=(0,t.useState)((()=>function(e){let{defaultValue:l,tabValues:r}=e;if(0===r.length)throw new Error("Docusaurus error: the <Tabs> component requires at least one <TabItem> children component");if(l){if(!h({value:l,tabValues:r}))throw new Error(`Docusaurus error: The <Tabs> has a defaultValue "${l}" but none of its children has the corresponding value. Available values are: ${r.map((e=>e.value)).join(", ")}. If you intend to show no default tab, use defaultValue={null} instead.`);return l}const t=r.find((e=>e.default))??r[0];if(!t)throw new Error("Unexpected error: 0 tabValues");return t.value}({defaultValue:l,tabValues:a}))),[c,p]=x({queryString:r,groupId:n}),[m,j]=function(e){let{groupId:l}=e;const r=function(e){return e?`docusaurus.tab.${e}`:null}(l),[n,a]=(0,d.Dv)(r);return[n,(0,t.useCallback)((e=>{r&&a.set(e)}),[r,a])]}({groupId:n}),v=(()=>{const e=c??m;return h({value:e,tabValues:a})?e:null})();(0,s.A)((()=>{v&&o(v)}),[v]);return{selectedValue:i,selectValue:(0,t.useCallback)((e=>{if(!h({value:e,tabValues:a}))throw new Error(`Can't select invalid tab value=${e}`);o(e),p(e),j(e)}),[p,j,a]),tabValues:a}}var j=r(2303);const v={tabList:"tabList__CuJ",tabItem:"tabItem_LNqP"};var g=r(4848);function _(e){let{className:l,block:r,selectedValue:t,selectValue:i,tabValues:s}=e;const o=[],{blockElementScrollPositionUntilNextRender:c}=(0,a.a_)(),d=e=>{const l=e.currentTarget,r=o.indexOf(l),n=s[r].value;n!==t&&(c(l),i(n))},p=e=>{let l=null;switch(e.key){case"Enter":d(e);break;case"ArrowRight":{const r=o.indexOf(e.currentTarget)+1;l=o[r]??o[0];break}case"ArrowLeft":{const r=o.indexOf(e.currentTarget)-1;l=o[r]??o[o.length-1];break}}l?.focus()};return(0,g.jsx)("ul",{role:"tablist","aria-orientation":"horizontal",className:(0,n.A)("tabs",{"tabs--block":r},l),children:s.map((e=>{let{value:l,label:r,attributes:a}=e;return(0,g.jsx)("li",{role:"tab",tabIndex:t===l?0:-1,"aria-selected":t===l,ref:e=>o.push(e),onKeyDown:p,onClick:d,...a,className:(0,n.A)("tabs__item",v.tabItem,a?.className,{"tabs__item--active":t===l}),children:r??l},l)}))})}function f(e){let{lazy:l,children:r,selectedValue:n}=e;const a=(Array.isArray(r)?r:[r]).filter(Boolean);if(l){const e=a.find((e=>e.props.value===n));return e?(0,t.cloneElement)(e,{className:"margin-top--md"}):null}return(0,g.jsx)("div",{className:"margin-top--md",children:a.map(((e,l)=>(0,t.cloneElement)(e,{key:l,hidden:e.props.value!==n})))})}function b(e){const l=m(e);return(0,g.jsxs)("div",{className:(0,n.A)("tabs-container",v.tabList),children:[(0,g.jsx)(_,{...l,...e}),(0,g.jsx)(f,{...l,...e})]})}function y(e){const l=(0,j.A)();return(0,g.jsx)(b,{...e,children:p(e.children)},String(l))}},8453:(e,l,r)=>{r.d(l,{R:()=>i,x:()=>s});var t=r(6540);const n={},a=t.createContext(n);function i(e){const l=t.useContext(a);return t.useMemo((function(){return"function"==typeof e?e(l):{...l,...e}}),[l,e])}function s(e){let l;return l=e.disableParentContext?"function"==typeof e.components?e.components(n):e.components||n:i(e.components),t.createElement(a.Provider,{value:l},e.children)}}}]);