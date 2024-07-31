"use strict";(self.webpackChunklightning_docs=self.webpackChunklightning_docs||[]).push([[8121],{5656:(e,n,t)=>{t.r(n),t.d(n,{assets:()=>d,contentTitle:()=>i,default:()=>x,frontMatter:()=>c,metadata:()=>o,toc:()=>h});var r=t(4848),s=t(8453),l=t(1470),a=t(9365);const c={sidebar_label:"Math",sidebar_position:10},i="Math",o={id:"Documentation/Math",title:"Math",description:"Math functions are built with templates. This means that you can use different types of parameters with these functions, such as int, float, double, etc.",source:"@site/docs/Documentation/Math.md",sourceDirName:"Documentation",slug:"/Documentation/Math",permalink:"/Lightninglib/docs/Documentation/Math",draft:!1,unlisted:!1,editUrl:"https://github.com/HectorAlonso18/Lightninglib/tree/main/docs/Documentation/Math.md",tags:[],version:"current",sidebarPosition:10,frontMatter:{sidebar_label:"Math",sidebar_position:10},sidebar:"tutorialSidebar",previous:{title:"Task Manager",permalink:"/Lightninglib/docs/Documentation/TaskManager"},next:{title:"Enumerated Values",permalink:"/Lightninglib/docs/Documentation/Enumerated Values"}},d={},h=[{value:"Math functions",id:"math-functions",level:2},{value:"sign()",id:"sign",level:3},{value:"Trigonometry",id:"trigonometry",level:2},{value:"to_rad()",id:"to_rad",level:3},{value:"to_degrees()",id:"to_degrees",level:3},{value:"reduce_angle_0_to_360()",id:"reduce_angle_0_to_360",level:3},{value:"reduce_angle_180_to_180()",id:"reduce_angle_180_to_180",level:3},{value:"get_angle_btw_points()",id:"get_angle_btw_points",level:3},{value:"distance_btw_points()",id:"distance_btw_points",level:3},{value:"Velocity",id:"velocity",level:2},{value:"rpm_to_linear()",id:"rpm_to_linear",level:3},{value:"linear_to_rpm()",id:"linear_to_rpm",level:3},{value:"Vector operations",id:"vector-operations",level:2},{value:"swap_vector()",id:"swap_vector",level:3},{value:"vector_add()",id:"vector_add",level:3},{value:"vector_sub()",id:"vector_sub",level:3},{value:"vector_dot()",id:"vector_dot",level:3},{value:"vector_mult()",id:"vector_mult",level:3}];function u(e){const n={admonition:"admonition",code:"code",h1:"h1",h2:"h2",h3:"h3",hr:"hr",mdxAdmonitionTitle:"mdxAdmonitionTitle",p:"p",pre:"pre",strong:"strong",table:"table",tbody:"tbody",td:"td",th:"th",thead:"thead",tr:"tr",...(0,s.R)(),...e.components};return(0,r.jsxs)(r.Fragment,{children:[(0,r.jsx)(n.h1,{id:"math",children:"Math"}),"\n",(0,r.jsx)(n.admonition,{type:"note",children:(0,r.jsxs)(n.p,{children:["Math functions are built with templates. This means that you can use different types of parameters with these functions, such as ",(0,r.jsx)(n.code,{children:"int"}),", ",(0,r.jsx)(n.code,{children:"float"}),", ",(0,r.jsx)(n.code,{children:"double"}),", etc.\r\nTemplates allow these functions to operate with various data types, providing flexibility and reusability in your code."]})}),"\n",(0,r.jsx)(n.h2,{id:"math-functions",children:"Math functions"}),"\n",(0,r.jsx)(n.h3,{id:"sign",children:"sign()"}),"\n",(0,r.jsx)(n.p,{children:"Sign function."}),"\n",(0,r.jsxs)(l.A,{groupId:"math_sign",defaultValue:"proto",values:[{label:"Prototype",value:"proto"},{label:"Example",value:"example"}],children:[(0,r.jsx)(a.A,{value:"proto",children:(0,r.jsx)(n.pre,{children:(0,r.jsx)(n.code,{className:"language-cpp",children:"template <typename T> T sign(const T &num);\r\n\n"})})}),(0,r.jsx)(a.A,{value:"example",children:(0,r.jsx)(n.pre,{children:(0,r.jsx)(n.code,{className:"language-cpp",children:"bool sign_number; \r\nsign_number = sign(-5); \r\n//sign_number equals to -1 \r\n\n"})})})]}),"\n",(0,r.jsxs)(n.table,{children:[(0,r.jsx)(n.thead,{children:(0,r.jsxs)(n.tr,{children:[(0,r.jsx)(n.th,{children:"Parameters"}),(0,r.jsx)(n.th,{})]})}),(0,r.jsx)(n.tbody,{children:(0,r.jsxs)(n.tr,{children:[(0,r.jsx)(n.td,{children:(0,r.jsx)(n.code,{children:"num"})}),(0,r.jsx)(n.td,{children:"A number."})]})})]}),"\n",(0,r.jsxs)(n.p,{children:[(0,r.jsx)(n.strong,{children:"Returns:"})," -1 if its negative or 1 if its positive."]}),"\n",(0,r.jsx)(n.hr,{}),"\n",(0,r.jsx)(n.h2,{id:"trigonometry",children:"Trigonometry"}),"\n",(0,r.jsx)(n.h3,{id:"to_rad",children:"to_rad()"}),"\n",(0,r.jsx)(n.p,{children:"Translates degrees to radians."}),"\n",(0,r.jsxs)(l.A,{groupId:"math_to_rad",defaultValue:"proto",values:[{label:"Prototype",value:"proto"},{label:"Example",value:"example"}],children:[(0,r.jsx)(a.A,{value:"proto",children:(0,r.jsx)(n.pre,{children:(0,r.jsx)(n.code,{className:"language-cpp",children:"template <typename T> T to_rad(const T &num)\r\n\n"})})}),(0,r.jsx)(a.A,{value:"example",children:(0,r.jsx)(n.pre,{children:(0,r.jsx)(n.code,{className:"language-cpp",children:'int degrees = 90; \r\nint radians = to_rad(degrees);\r\n\r\nstd::cout<<degrees<<" Degrees is equal to: "<<radians<<"radians"; \r\n\r\n//OUTPUT: 90 Degrees is equal to \u03c0/2 radians \n'})})})]}),"\n",(0,r.jsxs)(n.table,{children:[(0,r.jsx)(n.thead,{children:(0,r.jsxs)(n.tr,{children:[(0,r.jsx)(n.th,{children:"Parameters"}),(0,r.jsx)(n.th,{})]})}),(0,r.jsx)(n.tbody,{children:(0,r.jsxs)(n.tr,{children:[(0,r.jsx)(n.td,{children:(0,r.jsx)(n.code,{children:"num"})}),(0,r.jsx)(n.td,{children:"An angle in degrees."})]})})]}),"\n",(0,r.jsxs)(n.p,{children:[(0,r.jsx)(n.strong,{children:"Returns:"}),"  Angle in radians."]}),"\n",(0,r.jsx)(n.hr,{}),"\n",(0,r.jsx)(n.h3,{id:"to_degrees",children:"to_degrees()"}),"\n",(0,r.jsx)(n.p,{children:"Translates radians to degrees."}),"\n",(0,r.jsxs)(l.A,{groupId:"math_to_degrees",defaultValue:"proto",values:[{label:"Prototype",value:"proto"},{label:"Example",value:"example"}],children:[(0,r.jsx)(a.A,{value:"proto",children:(0,r.jsx)(n.pre,{children:(0,r.jsx)(n.code,{className:"language-cpp",children:"template <typename T> T to_degrees(const T &num)\r\n\n"})})}),(0,r.jsx)(a.A,{value:"example",children:(0,r.jsx)(n.pre,{children:(0,r.jsx)(n.code,{className:"language-cpp",children:'\r\nint radians = 3.141516; \r\nint degrees = to_rad(radians);\r\n\r\nstd::cout<<radians<<" Radians is equal to: "<<degrees<<"degrees"; \r\n\r\n//OUTPUT: 3.141516 Degrees is equal to 180 degrees\n'})})})]}),"\n",(0,r.jsxs)(n.table,{children:[(0,r.jsx)(n.thead,{children:(0,r.jsxs)(n.tr,{children:[(0,r.jsx)(n.th,{children:"Parameters"}),(0,r.jsx)(n.th,{})]})}),(0,r.jsx)(n.tbody,{children:(0,r.jsxs)(n.tr,{children:[(0,r.jsx)(n.td,{children:(0,r.jsx)(n.code,{children:"num"})}),(0,r.jsx)(n.td,{children:"An angle in radians."})]})})]}),"\n",(0,r.jsxs)(n.p,{children:[(0,r.jsx)(n.strong,{children:"Returns:"}),"  Angle in degrees."]}),"\n",(0,r.jsx)(n.hr,{}),"\n",(0,r.jsx)(n.h3,{id:"reduce_angle_0_to_360",children:"reduce_angle_0_to_360()"}),"\n",(0,r.jsx)(n.p,{children:"Puts angle in a 0-360 degrees range."}),"\n",(0,r.jsxs)(l.A,{groupId:"math_to_reduce_0_360",defaultValue:"proto",values:[{label:"Prototype",value:"proto"},{label:"Example",value:"example"}],children:[(0,r.jsx)(a.A,{value:"proto",children:(0,r.jsx)(n.pre,{children:(0,r.jsx)(n.code,{className:"language-cpp",children:"template <typename T> T reduce_angle_0_to_360(T degrees); \r\n\n"})})}),(0,r.jsx)(a.A,{value:"example",children:(0,r.jsx)(n.pre,{children:(0,r.jsx)(n.code,{className:"language-cpp",children:"int angle_out_of_range = 720; \r\nint angle_in_range= reduce_angle_0_to_360(angle_out_of_range);\r\n\r\n//angle_in_range is now equal to 360. \r\n\n"})})})]}),"\n",(0,r.jsxs)(n.table,{children:[(0,r.jsx)(n.thead,{children:(0,r.jsxs)(n.tr,{children:[(0,r.jsx)(n.th,{children:"Parameters"}),(0,r.jsx)(n.th,{})]})}),(0,r.jsx)(n.tbody,{children:(0,r.jsxs)(n.tr,{children:[(0,r.jsx)(n.td,{children:(0,r.jsx)(n.code,{children:"degrees"})}),(0,r.jsx)(n.td,{children:"An angle in degrees."})]})})]}),"\n",(0,r.jsxs)(n.p,{children:[(0,r.jsx)(n.strong,{children:"Returns:"})," The angle in degrees in range of 0-360 degrees."]}),"\n",(0,r.jsx)(n.hr,{}),"\n",(0,r.jsx)(n.h3,{id:"reduce_angle_180_to_180",children:"reduce_angle_180_to_180()"}),"\n",(0,r.jsx)(n.p,{children:"Put angle in a -180 -180 degrees range."}),"\n",(0,r.jsxs)(l.A,{groupId:"math_to_reduce_-180-180",defaultValue:"proto",values:[{label:"Prototype",value:"proto"},{label:"Example",value:"example"}],children:[(0,r.jsx)(a.A,{value:"proto",children:(0,r.jsx)(n.pre,{children:(0,r.jsx)(n.code,{className:"language-cpp",children:"template <typename T> T reduce_angle_180_to_180()\n"})})}),(0,r.jsx)(a.A,{value:"example",children:(0,r.jsx)(n.pre,{children:(0,r.jsx)(n.code,{className:"language-cpp",children:"int angle_out_of_range = 360; \r\nint angle_in_range= reduce_angle_180_to_180(angle_out_of_range);\r\n\r\n//angle_in_range is now equal to 180. \r\n\n"})})})]}),"\n",(0,r.jsxs)(n.table,{children:[(0,r.jsx)(n.thead,{children:(0,r.jsxs)(n.tr,{children:[(0,r.jsx)(n.th,{children:"Parameters"}),(0,r.jsx)(n.th,{})]})}),(0,r.jsx)(n.tbody,{children:(0,r.jsxs)(n.tr,{children:[(0,r.jsx)(n.td,{children:(0,r.jsx)(n.code,{children:"degrees"})}),(0,r.jsx)(n.td,{children:"An angle in degrees."})]})})]}),"\n",(0,r.jsxs)(n.p,{children:[(0,r.jsx)(n.strong,{children:"Returns:"})," The angle in degrees in range of -180-180 degrees."]}),"\n",(0,r.jsx)(n.hr,{}),"\n",(0,r.jsx)(n.h3,{id:"get_angle_btw_points",children:"get_angle_btw_points()"}),"\n",(0,r.jsx)(n.p,{children:"Gets the angle in degrees between two points."}),"\n",(0,r.jsxs)(l.A,{groupId:"math_angle_btw_points",defaultValue:"proto",values:[{label:"Prototype",value:"proto"},{label:"Example",value:"example"}],children:[(0,r.jsx)(a.A,{value:"proto",children:(0,r.jsx)(n.pre,{children:(0,r.jsx)(n.code,{className:"language-cpp",children:"auto get_angle_btw_points(const std::vector<T1> &current,\r\n                          const std::vector<T2> &target); \r\n\n"})})}),(0,r.jsx)(a.A,{value:"example",children:(0,r.jsx)(n.pre,{children:(0,r.jsx)(n.code,{className:"language-cpp",children:"std::vector<int> Point_1 = {0,0}; //current point (x1,y1), x1= 0, y1= 0\r\nstd::vector<int> Point_2 = {2,2}; //target point (x2,y2), x2=2, y2=2\r\n\r\nint angle_btw_points = get_angle_btw_points(Point_1,Point_2); \r\n\r\n//angle_btw_points is equal to: 45 degrees\r\n\n"})})})]}),"\n",(0,r.jsxs)(n.table,{children:[(0,r.jsx)(n.thead,{children:(0,r.jsxs)(n.tr,{children:[(0,r.jsx)(n.th,{children:"Parameters"}),(0,r.jsx)(n.th,{})]})}),(0,r.jsxs)(n.tbody,{children:[(0,r.jsxs)(n.tr,{children:[(0,r.jsx)(n.td,{children:(0,r.jsx)(n.code,{children:"current"})}),(0,r.jsx)(n.td,{children:"Current point."})]}),(0,r.jsxs)(n.tr,{children:[(0,r.jsx)(n.td,{children:(0,r.jsx)(n.code,{children:"target"})}),(0,r.jsx)(n.td,{children:"Target point."})]})]})]}),"\n",(0,r.jsxs)(n.p,{children:[(0,r.jsx)(n.strong,{children:"Returns:"})," The angle in degrees that exist between current and target points."]}),"\n",(0,r.jsx)(n.hr,{}),"\n",(0,r.jsx)(n.h3,{id:"distance_btw_points",children:"distance_btw_points()"}),"\n",(0,r.jsx)(n.p,{children:"Gets the distance between two points using Pythagoras."}),"\n",(0,r.jsxs)(l.A,{groupId:"math_to_dis_btw_points",defaultValue:"proto",values:[{label:"Prototype",value:"proto"},{label:"Example",value:"example"}],children:[(0,r.jsx)(a.A,{value:"proto",children:(0,r.jsx)(n.pre,{children:(0,r.jsx)(n.code,{className:"language-cpp",children:"auto distance_btw_points(const std::vector<T1> &p1, const std::vector<T2> &p2);\n"})})}),(0,r.jsx)(a.A,{value:"example",children:(0,r.jsx)(n.pre,{children:(0,r.jsx)(n.code,{className:"language-cpp",children:"std::vector<int> Point_1 = {0,0}; //current point (x1,y1), x1= 0, y1= 0\r\nstd::vector<int> Point_2 = {24,24}; //target point (x2,y2), x2=24, y2=24\r\n\r\nfloat distance = distace_btw_points(Point_1,Point_2); \r\n\r\n\r\n//distance is equal to: 33.94\r\n\n"})})})]}),"\n",(0,r.jsxs)(n.table,{children:[(0,r.jsx)(n.thead,{children:(0,r.jsxs)(n.tr,{children:[(0,r.jsx)(n.th,{children:"Parameters"}),(0,r.jsx)(n.th,{})]})}),(0,r.jsxs)(n.tbody,{children:[(0,r.jsxs)(n.tr,{children:[(0,r.jsx)(n.td,{children:(0,r.jsx)(n.code,{children:"p1"})}),(0,r.jsx)(n.td,{children:"Current point."})]}),(0,r.jsxs)(n.tr,{children:[(0,r.jsx)(n.td,{children:(0,r.jsx)(n.code,{children:"p2"})}),(0,r.jsx)(n.td,{children:"Target point."})]})]})]}),"\n",(0,r.jsxs)(n.p,{children:[(0,r.jsx)(n.strong,{children:"Returns:"}),"  Distance between current and target points."]}),"\n",(0,r.jsx)(n.hr,{}),"\n",(0,r.jsx)(n.h2,{id:"velocity",children:"Velocity"}),"\n",(0,r.jsxs)(n.admonition,{type:"note",children:[(0,r.jsx)(n.mdxAdmonitionTitle,{}),(0,r.jsxs)(n.p,{children:["The linear velocity is always in ",(0,r.jsx)(n.strong,{children:"distance/seconds units"}),"."]})]}),"\n",(0,r.jsx)(n.h3,{id:"rpm_to_linear",children:"rpm_to_linear()"}),"\n",(0,r.jsxs)(n.p,{children:["Convert a ",(0,r.jsx)(n.strong,{children:"RPM"})," velocity to a linear velocity ",(0,r.jsx)(n.strong,{children:"(distance/seconds)"}),"."]}),"\n",(0,r.jsxs)(l.A,{groupId:"math_rpm_to_linear",defaultValue:"proto",values:[{label:"Prototype",value:"proto"},{label:"Example",value:"example"},{label:"Example 2",value:"example_2"}],children:[(0,r.jsx)(a.A,{value:"proto",children:(0,r.jsx)(n.pre,{children:(0,r.jsx)(n.code,{className:"language-cpp",children:"auto rpm_to_linear(const T1 &rpm, const T2 &wheel_diameter);\n"})})}),(0,r.jsx)(a.A,{value:"example",children:(0,r.jsx)(n.pre,{children:(0,r.jsx)(n.code,{className:"language-cpp",children:"//Converting RPM to inches/second \r\nint RPM= 450; //RPM\r\nfloat wheel_diameter_inches = 3.25; //The wheel size\r\n\r\nfloat velocity_inches_second = rpm_to_linear(RPM,wheel_diameter_inches); //equivalent linear velocity  (inches/s)\r\n\n"})})}),(0,r.jsx)(a.A,{value:"example_2",children:(0,r.jsx)(n.pre,{children:(0,r.jsx)(n.code,{className:"language-cpp",children:"//Converting RPM to meters/second \r\nint RPM= 450; //RPM\r\nfloat wheel_diameter_meters = 0.08255; //The wheel size\r\n\r\nfloat velocity_inches_second = rpm_to_linear(RPM,wheel_diameter_meters); //equivalent linear velocity  (m/s)\r\n\n"})})})]}),"\n",(0,r.jsxs)(n.table,{children:[(0,r.jsx)(n.thead,{children:(0,r.jsxs)(n.tr,{children:[(0,r.jsx)(n.th,{children:"Parameters"}),(0,r.jsx)(n.th,{})]})}),(0,r.jsxs)(n.tbody,{children:[(0,r.jsxs)(n.tr,{children:[(0,r.jsx)(n.td,{children:(0,r.jsx)(n.code,{children:"rpm"})}),(0,r.jsx)(n.td,{children:"RPM velocity."})]}),(0,r.jsxs)(n.tr,{children:[(0,r.jsx)(n.td,{children:(0,r.jsx)(n.code,{children:"wheel_diameter"})}),(0,r.jsx)(n.td,{children:"The wheel size."})]})]})]}),"\n",(0,r.jsxs)(n.p,{children:[(0,r.jsx)(n.strong,{children:"Returns:"})," Velocity converted."]}),"\n",(0,r.jsx)(n.hr,{}),"\n",(0,r.jsx)(n.h3,{id:"linear_to_rpm",children:"linear_to_rpm()"}),"\n",(0,r.jsxs)(n.p,{children:["Convert a lineal velocity ",(0,r.jsx)(n.strong,{children:"(distance/seconds)"})," to a ",(0,r.jsx)(n.strong,{children:"RPM"}),"."]}),"\n",(0,r.jsx)(n.admonition,{type:"warning",children:(0,r.jsxs)(n.p,{children:["The distance units in the velocity and wheel diameter ",(0,r.jsx)(n.strong,{children:"must to be the same"}),"."]})}),"\n",(0,r.jsxs)(l.A,{groupId:"math_linear_rpm",defaultValue:"proto",values:[{label:"Prototype",value:"proto"},{label:"Example",value:"example"},{label:"Example 2",value:"example_2"}],children:[(0,r.jsx)(a.A,{value:"proto",children:(0,r.jsx)(n.pre,{children:(0,r.jsx)(n.code,{className:"language-cpp",children:"auto linear_to_rpm(const T1 &lineal_velocity, const T2 &wheel_diameter);\n"})})}),(0,r.jsx)(a.A,{value:"example",children:(0,r.jsx)(n.pre,{children:(0,r.jsx)(n.code,{className:"language-cpp",children:"//Converting inches/second to RPM \r\nint velocity_inches_second = 5; \r\nfloat wheel_diameter_inches = 3.25; //The wheel size\r\n\r\nfloat RPM = linear_to_rpm(velocity_inches_second, wheel_diameter_inches); //equivalent  RPM velocity. \r\n\n"})})}),(0,r.jsx)(a.A,{value:"example_2",children:(0,r.jsx)(n.pre,{children:(0,r.jsx)(n.code,{className:"language-cpp",children:"//Converting meters/second to RPM \r\nfloat velocity_meters_second = .25; \r\nfloat wheel_diameter_meters = 0.08255; //The wheel size\r\n\r\nfloat RPM = linear_to_rpm(velocity_meters_second, wheel_diameter_meters); //equivalent  RPM velocity.\r\n\n"})})})]}),"\n",(0,r.jsxs)(n.table,{children:[(0,r.jsx)(n.thead,{children:(0,r.jsxs)(n.tr,{children:[(0,r.jsx)(n.th,{children:"Parameters"}),(0,r.jsx)(n.th,{})]})}),(0,r.jsxs)(n.tbody,{children:[(0,r.jsxs)(n.tr,{children:[(0,r.jsx)(n.td,{children:(0,r.jsx)(n.code,{children:"lineal_velocity"})}),(0,r.jsx)(n.td,{children:"lineal velocity (distance/seconds)."})]}),(0,r.jsxs)(n.tr,{children:[(0,r.jsx)(n.td,{children:(0,r.jsx)(n.code,{children:"wheel_diameter"})}),(0,r.jsx)(n.td,{children:"The wheel size ."})]})]})]}),"\n",(0,r.jsxs)(n.p,{children:[(0,r.jsx)(n.strong,{children:"Returns:"})," Velocity converted."]}),"\n",(0,r.jsx)(n.hr,{}),"\n",(0,r.jsx)(n.h2,{id:"vector-operations",children:"Vector operations"}),"\n",(0,r.jsx)(n.h3,{id:"swap_vector",children:"swap_vector()"}),"\n",(0,r.jsx)(n.p,{children:"Swaps the first two elements of a vector."}),"\n",(0,r.jsxs)(l.A,{groupId:"math_swap_vector",defaultValue:"proto",values:[{label:"Prototype",value:"proto"},{label:"Example",value:"example"}],children:[(0,r.jsx)(a.A,{value:"proto",children:(0,r.jsx)(n.pre,{children:(0,r.jsx)(n.code,{className:"language-cpp",children:"template <typename T1> std::vector<T1> swap_vector(const std::vector<T1> &a);\n"})})}),(0,r.jsx)(a.A,{value:"example",children:(0,r.jsx)(n.pre,{children:(0,r.jsx)(n.code,{className:"language-cpp",children:"std::vector<int> Vector_1 = {0,24} // Vector_1 elements are: x1:0 , y1:24\r\n\r\nVector_1 = swap_vector(Vector_1); \r\n\r\n//Now Vector_1 elements are: x1:24 , y1:0\r\n\n"})})})]}),"\n",(0,r.jsxs)(n.table,{children:[(0,r.jsx)(n.thead,{children:(0,r.jsxs)(n.tr,{children:[(0,r.jsx)(n.th,{children:"Parameters"}),(0,r.jsx)(n.th,{})]})}),(0,r.jsx)(n.tbody,{children:(0,r.jsxs)(n.tr,{children:[(0,r.jsx)(n.td,{children:(0,r.jsx)(n.code,{children:"a"})}),(0,r.jsx)(n.td,{children:"The input vector."})]})})]}),"\n",(0,r.jsxs)(n.p,{children:[(0,r.jsx)(n.strong,{children:"Returns:"}),"  A vector with the first two elements swapped."]}),"\n",(0,r.jsx)(n.hr,{}),"\n",(0,r.jsx)(n.h3,{id:"vector_add",children:"vector_add()"}),"\n",(0,r.jsx)(n.p,{children:"Adds two vectors element-wise."}),"\n",(0,r.jsxs)(l.A,{groupId:"math_add_vector",defaultValue:"proto",values:[{label:"Prototype",value:"proto"},{label:"Example",value:"example"}],children:[(0,r.jsx)(a.A,{value:"proto",children:(0,r.jsx)(n.pre,{children:(0,r.jsx)(n.code,{className:"language-cpp",children:"std::vector<T1> vector_add(const std::vector<T1> &a, const std::vector<T1> &b);\n"})})}),(0,r.jsx)(a.A,{value:"example",children:(0,r.jsx)(n.pre,{children:(0,r.jsx)(n.code,{className:"language-cpp",children:"std::vector<int> Vector_a = {5,24}; \r\nstd::vector<int> Vector_b = {10,6}; \r\n\r\nstd::vector<int> Vector_c; \r\n\r\n//Vector_c is the result of: Vector_a + Vector_b\r\nVector_c = vector_add(Vector_a, Vector_b); \r\n\r\n//Vector_c elements are: (x:5+10 , y:24+6)\r\n//Vector_c elements are: (x:15   , y:30)\r\n\n"})})})]}),"\n",(0,r.jsxs)(n.table,{children:[(0,r.jsx)(n.thead,{children:(0,r.jsxs)(n.tr,{children:[(0,r.jsx)(n.th,{children:"Parameters"}),(0,r.jsx)(n.th,{})]})}),(0,r.jsxs)(n.tbody,{children:[(0,r.jsxs)(n.tr,{children:[(0,r.jsx)(n.td,{children:(0,r.jsx)(n.code,{children:"a"})}),(0,r.jsx)(n.td,{children:"The first input vector."})]}),(0,r.jsxs)(n.tr,{children:[(0,r.jsx)(n.td,{children:(0,r.jsx)(n.code,{children:"b"})}),(0,r.jsx)(n.td,{children:"The second input vector."})]})]})]}),"\n",(0,r.jsxs)(n.p,{children:[(0,r.jsx)(n.strong,{children:"Returns:"})," A vector with each element being the sum of the corresponding elements of a and b."]}),"\n",(0,r.jsx)(n.hr,{}),"\n",(0,r.jsx)(n.h3,{id:"vector_sub",children:"vector_sub()"}),"\n",(0,r.jsx)(n.p,{children:"Subtracts the second vector from the first vector element-wise."}),"\n",(0,r.jsxs)(l.A,{groupId:"math_sub_vector",defaultValue:"proto",values:[{label:"Prototype",value:"proto"},{label:"Example",value:"example"}],children:[(0,r.jsx)(a.A,{value:"proto",children:(0,r.jsx)(n.pre,{children:(0,r.jsx)(n.code,{className:"language-cpp",children:"std::vector<T1> vector_sub(const std::vector<T1> &a, const std::vector<T1> &b);\n"})})}),(0,r.jsx)(a.A,{value:"example",children:(0,r.jsx)(n.pre,{children:(0,r.jsx)(n.code,{className:"language-cpp",children:"std::vector<int> Vector_a = {5,24}; \r\nstd::vector<int> Vector_b = {10,6}; \r\n\r\nstd::vector<int> Vector_c; \r\n\r\n//Vector_c is the result of: Vector_a - Vector_b\r\nVector_c = vector_sub(Vector_a, Vector_b); \r\n\r\n//Vector_c elements are: (x:5-10 , y:24-6)\r\n//Vector_c elements are: (x:-5   , y:18)\r\n\n"})})})]}),"\n",(0,r.jsxs)(n.table,{children:[(0,r.jsx)(n.thead,{children:(0,r.jsxs)(n.tr,{children:[(0,r.jsx)(n.th,{children:"Parameters"}),(0,r.jsx)(n.th,{})]})}),(0,r.jsxs)(n.tbody,{children:[(0,r.jsxs)(n.tr,{children:[(0,r.jsx)(n.td,{children:(0,r.jsx)(n.code,{children:"a"})}),(0,r.jsx)(n.td,{children:"The first input vector."})]}),(0,r.jsxs)(n.tr,{children:[(0,r.jsx)(n.td,{children:(0,r.jsx)(n.code,{children:"b"})}),(0,r.jsx)(n.td,{children:"The second input vector."})]})]})]}),"\n",(0,r.jsxs)(n.p,{children:[(0,r.jsx)(n.strong,{children:"Returns:"}),"  A vector with each element being the difference of the corresponding elements of a and b."]}),"\n",(0,r.jsx)(n.hr,{}),"\n",(0,r.jsx)(n.h3,{id:"vector_dot",children:"vector_dot()"}),"\n",(0,r.jsx)(n.p,{children:"Computes the dot product of two vectors."}),"\n",(0,r.jsxs)(l.A,{groupId:"math_dot_vector",defaultValue:"proto",values:[{label:"Prototype",value:"proto"},{label:"Example",value:"example"}],children:[(0,r.jsx)(a.A,{value:"proto",children:(0,r.jsx)(n.pre,{children:(0,r.jsx)(n.code,{className:"language-cpp",children:"auto vector_dot(const std::vector<T1> &a, const std::vector<T1> &b);\n"})})}),(0,r.jsx)(a.A,{value:"example",children:(0,r.jsx)(n.pre,{children:(0,r.jsx)(n.code,{className:"language-cpp",children:"std::vector<int> Vector_a = {5,24}; \r\nstd::vector<int> Vector_b = {10,6}; \r\n\r\n//Making the dot product of Vector_a and Vector_b \r\nfloat dot_product = vector_dot (Vector_a,Vector_b); \n"})})})]}),"\n",(0,r.jsxs)(n.table,{children:[(0,r.jsx)(n.thead,{children:(0,r.jsxs)(n.tr,{children:[(0,r.jsx)(n.th,{children:"Parameters"}),(0,r.jsx)(n.th,{})]})}),(0,r.jsxs)(n.tbody,{children:[(0,r.jsxs)(n.tr,{children:[(0,r.jsx)(n.td,{children:(0,r.jsx)(n.code,{children:"a"})}),(0,r.jsx)(n.td,{children:"The first input vector."})]}),(0,r.jsxs)(n.tr,{children:[(0,r.jsx)(n.td,{children:(0,r.jsx)(n.code,{children:"b"})}),(0,r.jsx)(n.td,{children:"The second input vector."})]})]})]}),"\n",(0,r.jsxs)(n.p,{children:[(0,r.jsx)(n.strong,{children:"Returns:"}),"  The dot product of the vectors."]}),"\n",(0,r.jsx)(n.hr,{}),"\n",(0,r.jsx)(n.h3,{id:"vector_mult",children:"vector_mult()"}),"\n",(0,r.jsx)(n.p,{children:"Multiplies each element of a vector by a scalar."}),"\n",(0,r.jsxs)(l.A,{groupId:"math_mult_vector",defaultValue:"proto",values:[{label:"Prototype",value:"proto"},{label:"Example",value:"example"}],children:[(0,r.jsx)(a.A,{value:"proto",children:(0,r.jsx)(n.pre,{children:(0,r.jsx)(n.code,{className:"language-cpp",children:"std::vector<T1> vector_mult(const std::vector<T1> &a, const T2 b);\n"})})}),(0,r.jsx)(a.A,{value:"example",children:(0,r.jsx)(n.pre,{children:(0,r.jsx)(n.code,{className:"language-cpp",children:"//we will multiply vector_a to 2. \r\nstd::vector<int> Vector_a = {5,24}; \r\nint multiply_by = 2; \r\n\r\n\r\n//Vector_c is the result of: Vector_a * 2\r\n\r\nstd::vector<int> Vector_c = vector_mult(Vector_a, multiply_by); \r\n//Vector_c elements are: (x:5*2 , y:24*2)\r\n//Vector_c elements are: (x:10   , y:48)\r\n\n"})})})]}),"\n",(0,r.jsxs)(n.table,{children:[(0,r.jsx)(n.thead,{children:(0,r.jsxs)(n.tr,{children:[(0,r.jsx)(n.th,{children:"Parameters"}),(0,r.jsx)(n.th,{})]})}),(0,r.jsxs)(n.tbody,{children:[(0,r.jsxs)(n.tr,{children:[(0,r.jsx)(n.td,{children:(0,r.jsx)(n.code,{children:"a"})}),(0,r.jsx)(n.td,{children:"The input vector."})]}),(0,r.jsxs)(n.tr,{children:[(0,r.jsx)(n.td,{children:(0,r.jsx)(n.code,{children:"b"})}),(0,r.jsx)(n.td,{children:"The scalar value."})]})]})]}),"\n",(0,r.jsxs)(n.p,{children:[(0,r.jsx)(n.strong,{children:"Returns:"}),"  A vector with each element multiplied by the scalar."]}),"\n",(0,r.jsx)(n.hr,{})]})}function x(e={}){const{wrapper:n}={...(0,s.R)(),...e.components};return n?(0,r.jsx)(n,{...e,children:(0,r.jsx)(u,{...e})}):u(e)}},9365:(e,n,t)=>{t.d(n,{A:()=>a});t(6540);var r=t(4164);const s={tabItem:"tabItem_Ymn6"};var l=t(4848);function a(e){let{children:n,hidden:t,className:a}=e;return(0,l.jsx)("div",{role:"tabpanel",className:(0,r.A)(s.tabItem,a),hidden:t,children:n})}},1470:(e,n,t)=>{t.d(n,{A:()=>y});var r=t(6540),s=t(4164),l=t(3104),a=t(6347),c=t(205),i=t(7485),o=t(1682),d=t(679);function h(e){return r.Children.toArray(e).filter((e=>"\n"!==e)).map((e=>{if(!e||(0,r.isValidElement)(e)&&function(e){const{props:n}=e;return!!n&&"object"==typeof n&&"value"in n}(e))return e;throw new Error(`Docusaurus error: Bad <Tabs> child <${"string"==typeof e.type?e.type:e.type.name}>: all children of the <Tabs> component should be <TabItem>, and every <TabItem> should have a unique "value" prop.`)}))?.filter(Boolean)??[]}function u(e){const{values:n,children:t}=e;return(0,r.useMemo)((()=>{const e=n??function(e){return h(e).map((e=>{let{props:{value:n,label:t,attributes:r,default:s}}=e;return{value:n,label:t,attributes:r,default:s}}))}(t);return function(e){const n=(0,o.X)(e,((e,n)=>e.value===n.value));if(n.length>0)throw new Error(`Docusaurus error: Duplicate values "${n.map((e=>e.value)).join(", ")}" found in <Tabs>. Every value needs to be unique.`)}(e),e}),[n,t])}function x(e){let{value:n,tabValues:t}=e;return t.some((e=>e.value===n))}function p(e){let{queryString:n=!1,groupId:t}=e;const s=(0,a.W6)(),l=function(e){let{queryString:n=!1,groupId:t}=e;if("string"==typeof n)return n;if(!1===n)return null;if(!0===n&&!t)throw new Error('Docusaurus error: The <Tabs> component groupId prop is required if queryString=true, because this value is used as the search param name. You can also provide an explicit value such as queryString="my-search-param".');return t??null}({queryString:n,groupId:t});return[(0,i.aZ)(l),(0,r.useCallback)((e=>{if(!l)return;const n=new URLSearchParams(s.location.search);n.set(l,e),s.replace({...s.location,search:n.toString()})}),[l,s])]}function j(e){const{defaultValue:n,queryString:t=!1,groupId:s}=e,l=u(e),[a,i]=(0,r.useState)((()=>function(e){let{defaultValue:n,tabValues:t}=e;if(0===t.length)throw new Error("Docusaurus error: the <Tabs> component requires at least one <TabItem> children component");if(n){if(!x({value:n,tabValues:t}))throw new Error(`Docusaurus error: The <Tabs> has a defaultValue "${n}" but none of its children has the corresponding value. Available values are: ${t.map((e=>e.value)).join(", ")}. If you intend to show no default tab, use defaultValue={null} instead.`);return n}const r=t.find((e=>e.default))??t[0];if(!r)throw new Error("Unexpected error: 0 tabValues");return r.value}({defaultValue:n,tabValues:l}))),[o,h]=p({queryString:t,groupId:s}),[j,_]=function(e){let{groupId:n}=e;const t=function(e){return e?`docusaurus.tab.${e}`:null}(n),[s,l]=(0,d.Dv)(t);return[s,(0,r.useCallback)((e=>{t&&l.set(e)}),[t,l])]}({groupId:s}),m=(()=>{const e=o??j;return x({value:e,tabValues:l})?e:null})();(0,c.A)((()=>{m&&i(m)}),[m]);return{selectedValue:a,selectValue:(0,r.useCallback)((e=>{if(!x({value:e,tabValues:l}))throw new Error(`Can't select invalid tab value=${e}`);i(e),h(e),_(e)}),[h,_,l]),tabValues:l}}var _=t(2303);const m={tabList:"tabList__CuJ",tabItem:"tabItem_LNqP"};var v=t(4848);function g(e){let{className:n,block:t,selectedValue:r,selectValue:a,tabValues:c}=e;const i=[],{blockElementScrollPositionUntilNextRender:o}=(0,l.a_)(),d=e=>{const n=e.currentTarget,t=i.indexOf(n),s=c[t].value;s!==r&&(o(n),a(s))},h=e=>{let n=null;switch(e.key){case"Enter":d(e);break;case"ArrowRight":{const t=i.indexOf(e.currentTarget)+1;n=i[t]??i[0];break}case"ArrowLeft":{const t=i.indexOf(e.currentTarget)-1;n=i[t]??i[i.length-1];break}}n?.focus()};return(0,v.jsx)("ul",{role:"tablist","aria-orientation":"horizontal",className:(0,s.A)("tabs",{"tabs--block":t},n),children:c.map((e=>{let{value:n,label:t,attributes:l}=e;return(0,v.jsx)("li",{role:"tab",tabIndex:r===n?0:-1,"aria-selected":r===n,ref:e=>i.push(e),onKeyDown:h,onClick:d,...l,className:(0,s.A)("tabs__item",m.tabItem,l?.className,{"tabs__item--active":r===n}),children:t??n},n)}))})}function b(e){let{lazy:n,children:t,selectedValue:s}=e;const l=(Array.isArray(t)?t:[t]).filter(Boolean);if(n){const e=l.find((e=>e.props.value===s));return e?(0,r.cloneElement)(e,{className:"margin-top--md"}):null}return(0,v.jsx)("div",{className:"margin-top--md",children:l.map(((e,n)=>(0,r.cloneElement)(e,{key:n,hidden:e.props.value!==s})))})}function f(e){const n=j(e);return(0,v.jsxs)("div",{className:(0,s.A)("tabs-container",m.tabList),children:[(0,v.jsx)(g,{...n,...e}),(0,v.jsx)(b,{...n,...e})]})}function y(e){const n=(0,_.A)();return(0,v.jsx)(f,{...e,children:h(e.children)},String(n))}},8453:(e,n,t)=>{t.d(n,{R:()=>a,x:()=>c});var r=t(6540);const s={},l=r.createContext(s);function a(e){const n=r.useContext(l);return r.useMemo((function(){return"function"==typeof e?e(n):{...n,...e}}),[n,e])}function c(e){let n;return n=e.disableParentContext?"function"==typeof e.components?e.components(s):e.components||s:a(e.components),r.createElement(l.Provider,{value:n},e.children)}}}]);