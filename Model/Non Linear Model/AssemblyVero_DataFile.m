% Simscape(TM) Multibody(TM) version: 7.2

% This is a model data file derived from a Simscape Multibody Import XML file using the smimport function.
% The data in this file sets the block parameter values in an imported Simscape Multibody model.
% For more information on this file, see the smimport function help page in the Simscape Multibody documentation.
% You can modify numerical values, but avoid any other changes to this file.
% Do not add code to this file. Do not edit the physical units shown in comments.

%%%VariableName:smiData


%============= RigidTransform =============%

%Initialize the RigidTransform structure array by filling in null values.
smiData.RigidTransform(123).translation = [0.0 0.0 0.0];
smiData.RigidTransform(123).angle = 0.0;
smiData.RigidTransform(123).axis = [0.0 0.0 0.0];
smiData.RigidTransform(123).ID = '';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(1).translation = [-95.218668925622609 49.999999999992824 -20.000000000000995];  % mm
smiData.RigidTransform(1).angle = 2.0943951023932423;  % rad
smiData.RigidTransform(1).axis = [0.57735026918959476 0.57735026918964127 0.57735026918964127];
smiData.RigidTransform(1).ID = 'B[FirstJoint:1:-:Base_V2:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(2).translation = [84.281331074375771 240.99998209937985 -149.85753230832276];  % mm
smiData.RigidTransform(2).angle = 2.0943951023932104;  % rad
smiData.RigidTransform(2).axis = [0.57735026918962407 0.57735026918963062 0.57735026918962262];
smiData.RigidTransform(2).ID = 'F[FirstJoint:1:-:Base_V2:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(3).translation = [19.999999999999929 35.981329475411066 29.999999999997726];  % mm
smiData.RigidTransform(3).angle = 2.0943951023932064;  % rad
smiData.RigidTransform(3).axis = [0.57735026918962928 -0.57735026918962828 0.57735026918961974];
smiData.RigidTransform(3).ID = 'B[SecondJoint:1:-:FirstJoint:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(4).translation = [-29.99999999999984 117.49999999999974 32.999999999999865];  % mm
smiData.RigidTransform(4).angle = 2.0943951023931993;  % rad
smiData.RigidTransform(4).axis = [0.57735026918962706 -0.57735026918964139 0.57735026918960886];
smiData.RigidTransform(4).ID = 'F[SecondJoint:1:-:FirstJoint:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(5).translation = [188.49999999999881 240.9999820993803 -149.85753230832552];  % mm
smiData.RigidTransform(5).angle = 2.0943951023932055;  % rad
smiData.RigidTransform(5).axis = [-0.57735026918962618 -0.57735026918962007 0.57735026918963106];
smiData.RigidTransform(5).ID = 'AssemblyGround[Base_V2:1:FlangedBearing8mm:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(6).translation = [111.49999999999918 240.99999999999923 -149.99999999999869];  % mm
smiData.RigidTransform(6).angle = 2.0943951023931873;  % rad
smiData.RigidTransform(6).axis = [-0.5773502691896244 0.57735026918963206 -0.57735026918962096];
smiData.RigidTransform(6).ID = 'AssemblyGround[Base_V2:1:FlangedBearing8mm:2]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(7).translation = [299.9999999999992 0 -7.1054273576009615e-14];  % mm
smiData.RigidTransform(7).angle = 3.1415926535897931;  % rad
smiData.RigidTransform(7).axis = [-8.3738264463134558e-17 -0.70710678118654757 -0.70710678118654757];
smiData.RigidTransform(7).ID = 'AssemblyGround[Base_V2:1:BaseC_1:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(8).translation = [108.5000000000021 6.0000000000032285 -114.99999999999959];  % mm
smiData.RigidTransform(8).angle = 3.8818586242173693e-15;  % rad
smiData.RigidTransform(8).axis = [-0.8823262522407036 0.46436479249461721 -0.076588015369935744];
smiData.RigidTransform(8).ID = 'AssemblyGround[Base_V2:1:BaseC_2:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(9).translation = [108.49999999999883 5.9999999999999121 -187.99999999999574];  % mm
smiData.RigidTransform(9).angle = 1.5707963267948963;  % rad
smiData.RigidTransform(9).axis = [8.2896676752628083e-16 -1 -6.0883411479825812e-16];
smiData.RigidTransform(9).ID = 'AssemblyGround[Base_V2:1:BaseC_4:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(10).translation = [108.49999999999883 6.0000000000003162 -187.99999999999574];  % mm
smiData.RigidTransform(10).angle = 7.0250236198786251e-15;  % rad
smiData.RigidTransform(10).axis = [-0.93646201240054516 0.34373337503474571 0.069901832722355797];
smiData.RigidTransform(10).ID = 'AssemblyGround[Base_V2:1:BaseC_3:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(11).translation = [191.49999999999935 6.0000000000053149 -111.99999999999933];  % mm
smiData.RigidTransform(11).angle = 1.5707963267948786;  % rad
smiData.RigidTransform(11).axis = [-3.4250657716339741e-15 1 -2.6472933284825608e-15];
smiData.RigidTransform(11).ID = 'AssemblyGround[Base_V2:1:BaseC_4:2]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(12).translation = [249.90417249463079 236.93324981127012 -162.20520832149631];  % mm
smiData.RigidTransform(12).angle = 3.0262242460447193;  % rad
smiData.RigidTransform(12).axis = [0.70592674454703352 -0.057748269813458278 -0.7059267445470383];
smiData.RigidTransform(12).ID = 'AssemblyGround[Base_V2:1:Encoder:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(13).translation = [219.99999999999881 240.99999999999923 -149.99999999999994];  % mm
smiData.RigidTransform(13).angle = 2.0028524862247212;  % rad
smiData.RigidTransform(13).axis = [0.54327586879389134 0.54327586879389467 -0.64008019870363242];
smiData.RigidTransform(13).ID = 'AssemblyGround[Base_V2:1:MOTOR COUPLER CONNECTOR (1):1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(14).translation = [-204.52101520700151 0.31483765599976349 -262.56273342899789];  % mm
smiData.RigidTransform(14).angle = 2.094395102393193;  % rad
smiData.RigidTransform(14).axis = [-0.57735026918962706 -0.57735026918962529 -0.57735026918962506];
smiData.RigidTransform(14).ID = 'AssemblyGround[Base_V2:1:BaseC_6:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(15).translation = [242.49999999999875 221.74999999999903 -150.00000000000037];  % mm
smiData.RigidTransform(15).angle = 3.1415926535897856;  % rad
smiData.RigidTransform(15).axis = [0.70710678118654635 -2.5824345271547779e-15 -0.70710678118654868];
smiData.RigidTransform(15).ID = 'AssemblyGround[Base_V2:1:BaseC_7:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(16).translation = [181.49999999999952 56.000000000000043 -174.99999999999901];  % mm
smiData.RigidTransform(16).angle = 1.5707963267948961;  % rad
smiData.RigidTransform(16).axis = [1 2.2978252297578341e-16 -3.4080482543830113e-16];
smiData.RigidTransform(16).ID = 'AssemblyGround[Base_V2:1:20x20mm V-Slot:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(17).translation = [111.49999999999906 181.54556500594705 -169.99999999999892];  % mm
smiData.RigidTransform(17).angle = 1.5707963267948917;  % rad
smiData.RigidTransform(17).axis = [5.0653700214595383e-15 -1 -4.4905765354619975e-15];
smiData.RigidTransform(17).ID = 'AssemblyGround[Base_V2:1:BaseC_5:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(18).translation = [188.49999999999915 181.54556500594705 -129.99999999999912];  % mm
smiData.RigidTransform(18).angle = 1.5707963267949003;  % rad
smiData.RigidTransform(18).axis = [-5.5954898899116749e-15 1 -5.0362908466345414e-15];
smiData.RigidTransform(18).ID = 'AssemblyGround[Base_V2:1:BaseC_5:2]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(19).translation = [183.4999999999971 182.99999999999997 -187.99999999999997];  % mm
smiData.RigidTransform(19).angle = 2.0943951023931966;  % rad
smiData.RigidTransform(19).axis = [-0.57735026918962551 -0.57735026918962584 -0.57735026918962584];
smiData.RigidTransform(19).ID = 'AssemblyGround[Base_V2:1:BaseC_8:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(20).translation = [118.49999999999945 56.000000000000092 -174.99999999999932];  % mm
smiData.RigidTransform(20).angle = 3.1415926535897918;  % rad
smiData.RigidTransform(20).axis = [7.8504622934186675e-16 -0.70710678118654746 0.70710678118654757];
smiData.RigidTransform(20).ID = 'AssemblyGround[Base_V2:1:20x20mm V-Slot:2]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(21).translation = [181.49999999999935 56.000000000000071 -124.9999999999996];  % mm
smiData.RigidTransform(21).angle = 1.5707963267948966;  % rad
smiData.RigidTransform(21).axis = [1 2.2978252297578341e-16 -2.8529367420704168e-16];
smiData.RigidTransform(21).ID = 'AssemblyGround[Base_V2:1:20x20mm V-Slot:3]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(22).translation = [118.49999999999935 56.000000000000149 -124.99999999999946];  % mm
smiData.RigidTransform(22).angle = 2.0943951023931926;  % rad
smiData.RigidTransform(22).axis = [0.57735026918962751 -0.57735026918962506 0.57735026918962462];
smiData.RigidTransform(22).ID = 'AssemblyGround[Base_V2:1:20x20mm V-Slot:4]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(23).translation = [242.49999999999901 185.99999999999883 -169.25000000000006];  % mm
smiData.RigidTransform(23).angle = 2.0943951023931895;  % rad
smiData.RigidTransform(23).axis = [0.57735026918962562 -0.57735026918962251 0.57735026918962895];
smiData.RigidTransform(23).ID = 'AssemblyGround[Base_V2:1:BaseC_9:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(24).translation = [197.49999999999881 185.99999999999878 -169.24999999999986];  % mm
smiData.RigidTransform(24).angle = 3.1415926535897896;  % rad
smiData.RigidTransform(24).axis = [-1.901687878344954e-15 -1 4.5838222033184712e-15];
smiData.RigidTransform(24).ID = 'AssemblyGround[Base_V2:1:2020RightAngle:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(25).translation = [197.49999999999858 185.99999999999895 -147.74999999999997];  % mm
smiData.RigidTransform(25).angle = 3.1415926535897896;  % rad
smiData.RigidTransform(25).axis = [1.142735682555898e-15 -1 4.434635984384454e-15];
smiData.RigidTransform(25).ID = 'AssemblyGround[Base_V2:1:2020RightAngle:2]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(26).translation = [233.49999999999898 185.99999999999892 -152.25];  % mm
smiData.RigidTransform(26).angle = 1.2349005036100216e-14;  % rad
smiData.RigidTransform(26).axis = [-0.74237919410000375 0.27755768623435084 0.6097826358463011];
smiData.RigidTransform(26).ID = 'AssemblyGround[Base_V2:1:2020RightAngle:3]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(27).translation = [233.49999999999906 185.9999999999992 -130.75000000000023];  % mm
smiData.RigidTransform(27).angle = 1.2137884186316783e-14;  % rad
smiData.RigidTransform(27).axis = [-0.76100852536467234 0.25799404112069935 0.59523533083016655];
smiData.RigidTransform(27).ID = 'AssemblyGround[Base_V2:1:2020RightAngle:4]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(28).translation = [105.49999999999915 230.99999999999909 -149.99999999999878];  % mm
smiData.RigidTransform(28).angle = 1.570796326794893;  % rad
smiData.RigidTransform(28).axis = [4.8878003421316704e-15 -1 -4.4905765354620093e-15];
smiData.RigidTransform(28).ID = 'AssemblyGround[Base_V2:1:gard1:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(29).translation = [358.55899924599885 3.6275042130001456 -115.3035748119986];  % mm
smiData.RigidTransform(29).angle = 1.5707963267948959;  % rad
smiData.RigidTransform(29).axis = [-1 -2.3939131103030454e-15 -1.6388172914311708e-15];
smiData.RigidTransform(29).ID = 'AssemblyGround[Base_V2:1:guard 2:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(30).translation = [358.55899924599959 3.6275042130000923 -115.30357481199991];  % mm
smiData.RigidTransform(30).angle = 1.5707963267948981;  % rad
smiData.RigidTransform(30).axis = [-1 9.703974878818152e-16 1.2858929091394308e-15];
smiData.RigidTransform(30).ID = 'AssemblyGround[Base_V2:1:guard3:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(31).translation = [274.35391831100662 -138.65678185800189 379.01206560500782];  % mm
smiData.RigidTransform(31).angle = 2.0943951023932161;  % rad
smiData.RigidTransform(31).axis = [-0.57735026918962151 -0.57735026918963339 0.5773502691896224];
smiData.RigidTransform(31).ID = 'AssemblyGround[SecondJoint:1:Kerangka Bawah 1_10]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(32).translation = [-0.99999999999997868 -20.999999999998984 8.9999999999979963];  % mm
smiData.RigidTransform(32).angle = 3.1415926535897687;  % rad
smiData.RigidTransform(32).axis = [-0.70710678118654757 -0.70710678118654757 -1.2482235046545946e-14];
smiData.RigidTransform(32).ID = 'AssemblyGround[SecondJoint:1:Holder Tube-R8:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(33).translation = [-1.0000000000000142 -52.999999999999723 8.9999999999992397];  % mm
smiData.RigidTransform(33).angle = 3.1415926535897878;  % rad
smiData.RigidTransform(33).axis = [0.70710678118655068 0.70710678118654446 -7.844955468885239e-15];
smiData.RigidTransform(33).ID = 'AssemblyGround[SecondJoint:1:Holder Tube-R8:2]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(34).translation = [10.699999999999505 35.981329475410817 43.699999999997473];  % mm
smiData.RigidTransform(34).angle = 2.0943951023932486;  % rad
smiData.RigidTransform(34).axis = [-0.57735026918960364 -0.57735026918964738 -0.57735026918962629];
smiData.RigidTransform(34).ID = 'AssemblyGround[SecondJoint:1:shaft:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(35).translation = [-23.999999999999666 213.27222432699855 281.31653371798797];  % mm
smiData.RigidTransform(35).angle = 2.0943951023931633;  % rad
smiData.RigidTransform(35).axis = [-0.57735026918961996 0.57735026918962462 -0.57735026918963284];
smiData.RigidTransform(35).ID = 'AssemblyGround[SecondJoint:1:Part15:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(36).translation = [-301.75391831100035 -78.246912433556162 -366.76637001366322];  % mm
smiData.RigidTransform(36).angle = 2.1823011765652556;  % rad
smiData.RigidTransform(36).axis = [0.60391758545385543 0.52016064822242181 0.60391758545385565];
smiData.RigidTransform(36).ID = 'AssemblyGround[SecondJoint:1:Assembly1:1:Part1:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(37).translation = [-279.75391831100075 538.20482757010234 377.37038878460305];  % mm
smiData.RigidTransform(37).angle = 2.0943951023932001;  % rad
smiData.RigidTransform(37).axis = [-0.57735026918962806 0.57735026918962262 -0.57735026918962662];
smiData.RigidTransform(37).ID = 'AssemblyGround[SecondJoint:1:Assembly1:1:Part16:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(38).translation = [-310.75391831100006 -146.84650330589881 364.21763942060915];  % mm
smiData.RigidTransform(38).angle = 1.5707963267948966;  % rad
smiData.RigidTransform(38).axis = [-4.9960036108132107e-15 1 -5.0931481254679041e-15];
smiData.RigidTransform(38).ID = 'AssemblyGround[SecondJoint:1:Assembly1:1:Part17:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(39).translation = [5 212.33660542486496 -176.72768070052001];  % mm
smiData.RigidTransform(39).angle = 2.1823011765652653;  % rad
smiData.RigidTransform(39).axis = [0.60391758545385876 -0.52016064822241448 -0.60391758545385876];
smiData.RigidTransform(39).ID = 'AssemblyGround[SecondJoint:1:Assembly1:1:Part18:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(40).translation = [4.9737991503207013e-13 284.15797607462088 -43.037264169475513];  % mm
smiData.RigidTransform(40).angle = 1.5716291440451415;  % rad
smiData.RigidTransform(40).axis = [-0.028846562129927342 0.99916752934959241 -0.028846562129925358];
smiData.RigidTransform(40).ID = 'AssemblyGround[SecondJoint:1:Assembly1:1:spacers for prop:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(41).translation = [4.9737991503207013e-13 317.83246785662169 38.25169232152426];  % mm
smiData.RigidTransform(41).angle = 1.5716291440451398;  % rad
smiData.RigidTransform(41).axis = [-0.028846562129927322 0.99916752934959241 -0.028846562129925434];
smiData.RigidTransform(41).ID = 'AssemblyGround[SecondJoint:1:Assembly1:1:spacers for prop:2]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(42).translation = [5.6843418860808015e-13 202.83246785662038 -76.748307678474504];  % mm
smiData.RigidTransform(42).angle = 1.5716291440451418;  % rad
smiData.RigidTransform(42).axis = [-0.02884656212992754 0.99916752934959241 -0.028846562129925653];
smiData.RigidTransform(42).ID = 'AssemblyGround[SecondJoint:1:Assembly1:1:spacers for prop:3]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(43).translation = [4.9737991503207013e-13 121.5435113656207 -43.073815896473882];  % mm
smiData.RigidTransform(43).angle = 1.5716291440451415;  % rad
smiData.RigidTransform(43).axis = [-0.028846562129927342 0.99916752934959241 -0.028846562129925358];
smiData.RigidTransform(43).ID = 'AssemblyGround[SecondJoint:1:Assembly1:1:spacers for prop:4]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(44).translation = [4.2632564145606011e-13 284.12142434662235 119.57720053952478];  % mm
smiData.RigidTransform(44).angle = 1.5716291440451398;  % rad
smiData.RigidTransform(44).axis = [-0.028846562129927322 0.99916752934959241 -0.028846562129925434];
smiData.RigidTransform(44).ID = 'AssemblyGround[SecondJoint:1:Assembly1:1:spacers for prop:5]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(45).translation = [4.9737991503207013e-13 121.50695963862198 119.54064881152661];  % mm
smiData.RigidTransform(45).angle = 1.5716291440451386;  % rad
smiData.RigidTransform(45).axis = [-0.028846562129926326 0.99916752934959241 -0.028846562129924654];
smiData.RigidTransform(45).ID = 'AssemblyGround[SecondJoint:1:Assembly1:1:spacers for prop:6]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(46).translation = [4.9737991503207013e-13 87.83246785662115 38.251692321526747];  % mm
smiData.RigidTransform(46).angle = 1.5716291440451429;  % rad
smiData.RigidTransform(46).axis = [-0.028846562129927433 0.99916752934959241 -0.028846562129925438];
smiData.RigidTransform(46).ID = 'AssemblyGround[SecondJoint:1:Assembly1:1:spacers for prop:7]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(47).translation = [4.2632564145606011e-13 202.83246785662232 153.25169232152598];  % mm
smiData.RigidTransform(47).angle = 1.5716291440451398;  % rad
smiData.RigidTransform(47).axis = [-0.028846562129927322 0.99916752934959241 -0.028846562129925434];
smiData.RigidTransform(47).ID = 'AssemblyGround[SecondJoint:1:Assembly1:1:spacers for prop:8]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(48).translation = [-45 208.9793599167858 4.2603516626174098];  % mm
smiData.RigidTransform(48).angle = 2.626810330208952;  % rad
smiData.RigidTransform(48).axis = [-0.68216931914308065 0.26323001356177089 -0.68216931914308165];
smiData.RigidTransform(48).ID = 'AssemblyGround[SecondJoint:1:Assembly1:1:Standoff M3 M-M H 45mm:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(49).translation = [-45 194.34722732959847 23.3166309839158];  % mm
smiData.RigidTransform(49).angle = 2.4147220532998368;  % rad
smiData.RigidTransform(49).axis = [-0.65396831917925413 0.38032995545936371 -0.65396831917925469];
smiData.RigidTransform(49).ID = 'AssemblyGround[SecondJoint:1:Assembly1:1:Standoff M3 M-M H 45mm:2]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(50).translation = [-45 228.52737034220593 25.734123846372228];  % mm
smiData.RigidTransform(50).angle = 2.2485432175187938;  % rad
smiData.RigidTransform(50).axis = [-0.6207952652500861 0.47877601995729646 -0.62079526525008688];
smiData.RigidTransform(50).ID = 'AssemblyGround[SecondJoint:1:Assembly1:1:Standoff M3 M-M H 45mm:3]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(51).translation = [-45 204.77026489005655 35.19141174548821];  % mm
smiData.RigidTransform(51).angle = 2.9616099044498512;  % rad
smiData.RigidTransform(51).axis = [-0.70422213390634825 0.090235094241527578 -0.70422213390634902];
smiData.RigidTransform(51).ID = 'AssemblyGround[SecondJoint:1:Assembly1:1:Standoff M3 M-M H 45mm:4]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(52).translation = [-59.999999999999822 169.02417289341045 -172.34534535109634];  % mm
smiData.RigidTransform(52).angle = 3.1415926535897931;  % rad
smiData.RigidTransform(52).axis = [1.3593031908067825e-15 -0.70710678118654857 -0.70710678118654646];
smiData.RigidTransform(52).ID = 'AssemblyGround[SecondJoint:1:Assembly1:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(53).translation = [-301.75391831100035 -78.246912433556091 -366.76637001366316];  % mm
smiData.RigidTransform(53).angle = 2.1823011765652556;  % rad
smiData.RigidTransform(53).axis = [0.60391758545385543 0.52016064822242181 0.60391758545385565];
smiData.RigidTransform(53).ID = 'AssemblyGround[SecondJoint:1:Assembly1:2:Part1:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(54).translation = [-279.75391831100069 538.20482757010245 377.37038878460294];  % mm
smiData.RigidTransform(54).angle = 2.0943951023932001;  % rad
smiData.RigidTransform(54).axis = [-0.57735026918962806 0.57735026918962262 -0.57735026918962662];
smiData.RigidTransform(54).ID = 'AssemblyGround[SecondJoint:1:Assembly1:2:Part16:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(55).translation = [-310.75391831100006 -146.84650330589878 364.21763942060909];  % mm
smiData.RigidTransform(55).angle = 1.5707963267948966;  % rad
smiData.RigidTransform(55).axis = [-4.9960036108177869e-15 1 -5.093148125469533e-15];
smiData.RigidTransform(55).ID = 'AssemblyGround[SecondJoint:1:Assembly1:2:Part17:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(56).translation = [5 212.33660542486496 -176.72768070052007];  % mm
smiData.RigidTransform(56).angle = 2.1823011765652653;  % rad
smiData.RigidTransform(56).axis = [0.60391758545385876 -0.52016064822241448 -0.60391758545385876];
smiData.RigidTransform(56).ID = 'AssemblyGround[SecondJoint:1:Assembly1:2:Part18:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(57).translation = [4.9737991503207013e-13 284.15797607462088 -43.037264169475549];  % mm
smiData.RigidTransform(57).angle = 1.5716291440451415;  % rad
smiData.RigidTransform(57).axis = [-0.028846562129927342 0.99916752934959241 -0.028846562129925358];
smiData.RigidTransform(57).ID = 'AssemblyGround[SecondJoint:1:Assembly1:2:spacers for prop:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(58).translation = [4.2632564145606011e-13 317.83246785662169 38.251692321524331];  % mm
smiData.RigidTransform(58).angle = 1.5716291440451398;  % rad
smiData.RigidTransform(58).axis = [-0.028846562129927322 0.99916752934959241 -0.028846562129925434];
smiData.RigidTransform(58).ID = 'AssemblyGround[SecondJoint:1:Assembly1:2:spacers for prop:2]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(59).translation = [5.6843418860808015e-13 202.83246785662038 -76.748307678474532];  % mm
smiData.RigidTransform(59).angle = 1.5716291440451418;  % rad
smiData.RigidTransform(59).axis = [-0.02884656212992754 0.99916752934959241 -0.028846562129925653];
smiData.RigidTransform(59).ID = 'AssemblyGround[SecondJoint:1:Assembly1:2:spacers for prop:3]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(60).translation = [4.9737991503207013e-13 121.54351136562072 -43.073815896473917];  % mm
smiData.RigidTransform(60).angle = 1.5716291440451415;  % rad
smiData.RigidTransform(60).axis = [-0.028846562129927342 0.99916752934959241 -0.028846562129925358];
smiData.RigidTransform(60).ID = 'AssemblyGround[SecondJoint:1:Assembly1:2:spacers for prop:4]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(61).translation = [4.2632564145606011e-13 284.1214243466224 119.57720053952478];  % mm
smiData.RigidTransform(61).angle = 1.5716291440451398;  % rad
smiData.RigidTransform(61).axis = [-0.028846562129927322 0.99916752934959241 -0.028846562129925434];
smiData.RigidTransform(61).ID = 'AssemblyGround[SecondJoint:1:Assembly1:2:spacers for prop:5]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(62).translation = [5.6843418860808015e-13 121.50695963862198 119.54064881152661];  % mm
smiData.RigidTransform(62).angle = 1.5716291440451386;  % rad
smiData.RigidTransform(62).axis = [-0.028846562129926326 0.99916752934959241 -0.028846562129924654];
smiData.RigidTransform(62).ID = 'AssemblyGround[SecondJoint:1:Assembly1:2:spacers for prop:6]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(63).translation = [5.6843418860808015e-13 87.832467856621122 38.251692321526747];  % mm
smiData.RigidTransform(63).angle = 1.5716291440451429;  % rad
smiData.RigidTransform(63).axis = [-0.028846562129927433 0.99916752934959241 -0.028846562129925438];
smiData.RigidTransform(63).ID = 'AssemblyGround[SecondJoint:1:Assembly1:2:spacers for prop:7]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(64).translation = [4.9737991503207013e-13 202.83246785662237 153.25169232152589];  % mm
smiData.RigidTransform(64).angle = 1.5716291440451398;  % rad
smiData.RigidTransform(64).axis = [-0.028846562129927322 0.99916752934959241 -0.028846562129925434];
smiData.RigidTransform(64).ID = 'AssemblyGround[SecondJoint:1:Assembly1:2:spacers for prop:8]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(65).translation = [-45 208.9793599167858 4.2603516626173388];  % mm
smiData.RigidTransform(65).angle = 2.626810330208952;  % rad
smiData.RigidTransform(65).axis = [-0.68216931914308065 0.26323001356177089 -0.68216931914308165];
smiData.RigidTransform(65).ID = 'AssemblyGround[SecondJoint:1:Assembly1:2:Standoff M3 M-M H 45mm:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(66).translation = [-45 194.34722732959852 23.3166309839158];  % mm
smiData.RigidTransform(66).angle = 2.4147220532998368;  % rad
smiData.RigidTransform(66).axis = [-0.65396831917925402 0.38032995545936371 -0.65396831917925469];
smiData.RigidTransform(66).ID = 'AssemblyGround[SecondJoint:1:Assembly1:2:Standoff M3 M-M H 45mm:2]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(67).translation = [-44.999999999999929 228.52737034220587 25.734123846372157];  % mm
smiData.RigidTransform(67).angle = 2.2485432175187938;  % rad
smiData.RigidTransform(67).axis = [-0.6207952652500861 0.47877601995729646 -0.62079526525008688];
smiData.RigidTransform(67).ID = 'AssemblyGround[SecondJoint:1:Assembly1:2:Standoff M3 M-M H 45mm:3]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(68).translation = [-45 204.77026489005658 35.19141174548821];  % mm
smiData.RigidTransform(68).angle = 2.9616099044498512;  % rad
smiData.RigidTransform(68).axis = [-0.70422213390634825 0.090235094241527578 -0.70422213390634913];
smiData.RigidTransform(68).ID = 'AssemblyGround[SecondJoint:1:Assembly1:2:Standoff M3 M-M H 45mm:4]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(69).translation = [-59.999999999976446 -232.34551132739551 -169.02416022221377];  % mm
smiData.RigidTransform(69).angle = 3.1415926535897603;  % rad
smiData.RigidTransform(69).axis = [-1.8919951642842644e-14 1 -3.0120373995532124e-11];
smiData.RigidTransform(69).ID = 'AssemblyGround[SecondJoint:1:Assembly1:2]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(70).translation = [-301.75391831100046 -78.246912433556091 -366.76637001366316];  % mm
smiData.RigidTransform(70).angle = 2.1823011765652556;  % rad
smiData.RigidTransform(70).axis = [0.60391758545385543 0.52016064822242181 0.60391758545385565];
smiData.RigidTransform(70).ID = 'AssemblyGround[SecondJoint:1:Assembly1:3:Part1:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(71).translation = [-279.75391831100063 538.20482757010245 377.37038878460294];  % mm
smiData.RigidTransform(71).angle = 2.0943951023932001;  % rad
smiData.RigidTransform(71).axis = [-0.57735026918962806 0.57735026918962262 -0.57735026918962662];
smiData.RigidTransform(71).ID = 'AssemblyGround[SecondJoint:1:Assembly1:3:Part16:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(72).translation = [-310.75391831100006 -146.84650330589878 364.21763942060915];  % mm
smiData.RigidTransform(72).angle = 1.5707963267948966;  % rad
smiData.RigidTransform(72).axis = [-4.9960036108132107e-15 1 -5.0931481254679048e-15];
smiData.RigidTransform(72).ID = 'AssemblyGround[SecondJoint:1:Assembly1:3:Part17:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(73).translation = [4.9999999999999289 212.33660542486496 -176.72768070052001];  % mm
smiData.RigidTransform(73).angle = 2.1823011765652653;  % rad
smiData.RigidTransform(73).axis = [0.60391758545385876 -0.52016064822241448 -0.60391758545385876];
smiData.RigidTransform(73).ID = 'AssemblyGround[SecondJoint:1:Assembly1:3:Part18:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(74).translation = [4.9737991503207013e-13 284.15797607462088 -43.037264169475513];  % mm
smiData.RigidTransform(74).angle = 1.5716291440451415;  % rad
smiData.RigidTransform(74).axis = [-0.028846562129927342 0.99916752934959241 -0.028846562129925358];
smiData.RigidTransform(74).ID = 'AssemblyGround[SecondJoint:1:Assembly1:3:spacers for prop:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(75).translation = [4.9737991503207013e-13 317.83246785662175 38.251692321524274];  % mm
smiData.RigidTransform(75).angle = 1.5716291440451398;  % rad
smiData.RigidTransform(75).axis = [-0.028846562129927322 0.99916752934959241 -0.028846562129925434];
smiData.RigidTransform(75).ID = 'AssemblyGround[SecondJoint:1:Assembly1:3:spacers for prop:2]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(76).translation = [5.6843418860808015e-13 202.83246785662044 -76.748307678474518];  % mm
smiData.RigidTransform(76).angle = 1.5716291440451418;  % rad
smiData.RigidTransform(76).axis = [-0.02884656212992754 0.99916752934959241 -0.028846562129925653];
smiData.RigidTransform(76).ID = 'AssemblyGround[SecondJoint:1:Assembly1:3:spacers for prop:3]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(77).translation = [5.6843418860808015e-13 121.54351136562073 -43.073815896473874];  % mm
smiData.RigidTransform(77).angle = 1.5716291440451415;  % rad
smiData.RigidTransform(77).axis = [-0.028846562129927342 0.99916752934959241 -0.028846562129925358];
smiData.RigidTransform(77).ID = 'AssemblyGround[SecondJoint:1:Assembly1:3:spacers for prop:4]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(78).translation = [4.9737991503207013e-13 284.12142434662246 119.5772005395248];  % mm
smiData.RigidTransform(78).angle = 1.5716291440451398;  % rad
smiData.RigidTransform(78).axis = [-0.028846562129927322 0.99916752934959241 -0.028846562129925434];
smiData.RigidTransform(78).ID = 'AssemblyGround[SecondJoint:1:Assembly1:3:spacers for prop:5]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(79).translation = [5.6843418860808015e-13 121.50695963862198 119.54064881152655];  % mm
smiData.RigidTransform(79).angle = 1.5716291440451386;  % rad
smiData.RigidTransform(79).axis = [-0.028846562129926326 0.99916752934959241 -0.028846562129924654];
smiData.RigidTransform(79).ID = 'AssemblyGround[SecondJoint:1:Assembly1:3:spacers for prop:6]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(80).translation = [5.6843418860808015e-13 87.832467856621122 38.251692321526733];  % mm
smiData.RigidTransform(80).angle = 1.5716291440451429;  % rad
smiData.RigidTransform(80).axis = [-0.028846562129927433 0.99916752934959241 -0.028846562129925438];
smiData.RigidTransform(80).ID = 'AssemblyGround[SecondJoint:1:Assembly1:3:spacers for prop:7]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(81).translation = [4.9737991503207013e-13 202.8324678566224 153.25169232152592];  % mm
smiData.RigidTransform(81).angle = 1.5716291440451398;  % rad
smiData.RigidTransform(81).axis = [-0.028846562129927322 0.99916752934959241 -0.028846562129925434];
smiData.RigidTransform(81).ID = 'AssemblyGround[SecondJoint:1:Assembly1:3:spacers for prop:8]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(82).translation = [-45 208.9793599167858 4.2603516626174098];  % mm
smiData.RigidTransform(82).angle = 2.626810330208952;  % rad
smiData.RigidTransform(82).axis = [-0.68216931914308065 0.26323001356177089 -0.68216931914308165];
smiData.RigidTransform(82).ID = 'AssemblyGround[SecondJoint:1:Assembly1:3:Standoff M3 M-M H 45mm:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(83).translation = [-45 194.34722732959855 23.316630983915807];  % mm
smiData.RigidTransform(83).angle = 2.4147220532998368;  % rad
smiData.RigidTransform(83).axis = [-0.65396831917925402 0.38032995545936371 -0.65396831917925469];
smiData.RigidTransform(83).ID = 'AssemblyGround[SecondJoint:1:Assembly1:3:Standoff M3 M-M H 45mm:2]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(84).translation = [-44.999999999999929 228.52737034220598 25.734123846372245];  % mm
smiData.RigidTransform(84).angle = 2.2485432175187938;  % rad
smiData.RigidTransform(84).axis = [-0.6207952652500861 0.47877601995729646 -0.62079526525008688];
smiData.RigidTransform(84).ID = 'AssemblyGround[SecondJoint:1:Assembly1:3:Standoff M3 M-M H 45mm:3]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(85).translation = [-44.999999999999929 204.77026489005658 35.191411745488246];  % mm
smiData.RigidTransform(85).angle = 2.9616099044498512;  % rad
smiData.RigidTransform(85).axis = [-0.70422213390634825 0.090235094241527578 -0.70422213390634913];
smiData.RigidTransform(85).ID = 'AssemblyGround[SecondJoint:1:Assembly1:3:Standoff M3 M-M H 45mm:4]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(86).translation = [-59.999999999992006 -229.02519693841344 232.34549806109936];  % mm
smiData.RigidTransform(86).angle = 3.141592653589746;  % rad
smiData.RigidTransform(86).axis = [-2.4001404187818551e-15 0.70710678118656189 -0.70710678118653325];
smiData.RigidTransform(86).ID = 'AssemblyGround[SecondJoint:1:Assembly1:3]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(87).translation = [-301.75391831100046 -78.246912433556162 -366.76637001366316];  % mm
smiData.RigidTransform(87).angle = 2.1823011765652556;  % rad
smiData.RigidTransform(87).axis = [0.60391758545385543 0.52016064822242181 0.60391758545385565];
smiData.RigidTransform(87).ID = 'AssemblyGround[SecondJoint:1:Assembly1:4:Part1:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(88).translation = [-279.75391831100075 538.20482757010234 377.37038878460282];  % mm
smiData.RigidTransform(88).angle = 2.0943951023932001;  % rad
smiData.RigidTransform(88).axis = [-0.57735026918962806 0.57735026918962262 -0.57735026918962662];
smiData.RigidTransform(88).ID = 'AssemblyGround[SecondJoint:1:Assembly1:4:Part16:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(89).translation = [-310.75391831100006 -146.84650330589881 364.21763942060909];  % mm
smiData.RigidTransform(89).angle = 1.5707963267948966;  % rad
smiData.RigidTransform(89).axis = [-4.996003610813195e-15 1 -5.0931481254678883e-15];
smiData.RigidTransform(89).ID = 'AssemblyGround[SecondJoint:1:Assembly1:4:Part17:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(90).translation = [5 212.3366054248649 -176.72768070052001];  % mm
smiData.RigidTransform(90).angle = 2.1823011765652653;  % rad
smiData.RigidTransform(90).axis = [0.60391758545385876 -0.52016064822241448 -0.60391758545385876];
smiData.RigidTransform(90).ID = 'AssemblyGround[SecondJoint:1:Assembly1:4:Part18:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(91).translation = [4.9737991503207013e-13 284.15797607462076 -43.037264169475506];  % mm
smiData.RigidTransform(91).angle = 1.5716291440451415;  % rad
smiData.RigidTransform(91).axis = [-0.028846562129927342 0.99916752934959241 -0.028846562129925358];
smiData.RigidTransform(91).ID = 'AssemblyGround[SecondJoint:1:Assembly1:4:spacers for prop:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(92).translation = [4.9737991503207013e-13 317.83246785662163 38.251692321524246];  % mm
smiData.RigidTransform(92).angle = 1.5716291440451398;  % rad
smiData.RigidTransform(92).axis = [-0.028846562129927322 0.99916752934959241 -0.028846562129925434];
smiData.RigidTransform(92).ID = 'AssemblyGround[SecondJoint:1:Assembly1:4:spacers for prop:2]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(93).translation = [5.6843418860808015e-13 202.8324678566203 -76.748307678474518];  % mm
smiData.RigidTransform(93).angle = 1.5716291440451418;  % rad
smiData.RigidTransform(93).axis = [-0.02884656212992754 0.99916752934959241 -0.028846562129925653];
smiData.RigidTransform(93).ID = 'AssemblyGround[SecondJoint:1:Assembly1:4:spacers for prop:3]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(94).translation = [4.9737991503207013e-13 121.5435113656207 -43.073815896473874];  % mm
smiData.RigidTransform(94).angle = 1.5716291440451415;  % rad
smiData.RigidTransform(94).axis = [-0.028846562129927342 0.99916752934959241 -0.028846562129925358];
smiData.RigidTransform(94).ID = 'AssemblyGround[SecondJoint:1:Assembly1:4:spacers for prop:4]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(95).translation = [4.2632564145606011e-13 284.12142434662235 119.5772005395248];  % mm
smiData.RigidTransform(95).angle = 1.5716291440451398;  % rad
smiData.RigidTransform(95).axis = [-0.028846562129927322 0.99916752934959241 -0.028846562129925434];
smiData.RigidTransform(95).ID = 'AssemblyGround[SecondJoint:1:Assembly1:4:spacers for prop:5]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(96).translation = [5.6843418860808015e-13 121.50695963862194 119.54064881152655];  % mm
smiData.RigidTransform(96).angle = 1.5716291440451386;  % rad
smiData.RigidTransform(96).axis = [-0.028846562129926326 0.99916752934959241 -0.028846562129924654];
smiData.RigidTransform(96).ID = 'AssemblyGround[SecondJoint:1:Assembly1:4:spacers for prop:6]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(97).translation = [4.9737991503207013e-13 87.832467856621037 38.25169232152669];  % mm
smiData.RigidTransform(97).angle = 1.5716291440451429;  % rad
smiData.RigidTransform(97).axis = [-0.028846562129927433 0.99916752934959241 -0.028846562129925438];
smiData.RigidTransform(97).ID = 'AssemblyGround[SecondJoint:1:Assembly1:4:spacers for prop:7]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(98).translation = [4.2632564145606011e-13 202.83246785662232 153.25169232152592];  % mm
smiData.RigidTransform(98).angle = 1.5716291440451398;  % rad
smiData.RigidTransform(98).axis = [-0.028846562129927322 0.99916752934959241 -0.028846562129925434];
smiData.RigidTransform(98).ID = 'AssemblyGround[SecondJoint:1:Assembly1:4:spacers for prop:8]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(99).translation = [-45 208.97935991678571 4.2603516626174009];  % mm
smiData.RigidTransform(99).angle = 2.626810330208952;  % rad
smiData.RigidTransform(99).axis = [-0.68216931914308065 0.26323001356177089 -0.68216931914308165];
smiData.RigidTransform(99).ID = 'AssemblyGround[SecondJoint:1:Assembly1:4:Standoff M3 M-M H 45mm:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(100).translation = [-44.999999999999929 194.34722732959847 23.316630983915818];  % mm
smiData.RigidTransform(100).angle = 2.4147220532998368;  % rad
smiData.RigidTransform(100).axis = [-0.65396831917925413 0.38032995545936371 -0.65396831917925469];
smiData.RigidTransform(100).ID = 'AssemblyGround[SecondJoint:1:Assembly1:4:Standoff M3 M-M H 45mm:2]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(101).translation = [-44.999999999999929 228.52737034220587 25.734123846372245];  % mm
smiData.RigidTransform(101).angle = 2.2485432175187938;  % rad
smiData.RigidTransform(101).axis = [-0.6207952652500861 0.47877601995729646 -0.62079526525008688];
smiData.RigidTransform(101).ID = 'AssemblyGround[SecondJoint:1:Assembly1:4:Standoff M3 M-M H 45mm:3]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(102).translation = [-45 204.77026489005655 35.191411745488246];  % mm
smiData.RigidTransform(102).angle = 2.9616099044498512;  % rad
smiData.RigidTransform(102).axis = [-0.70422213390634825 0.090235094241527578 -0.70422213390634902];
smiData.RigidTransform(102).ID = 'AssemblyGround[SecondJoint:1:Assembly1:4:Standoff M3 M-M H 45mm:4]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(103).translation = [-60.000000000006928 172.34551132909132 229.02416023339796];  % mm
smiData.RigidTransform(103).angle = 3.1415926535897554;  % rad
smiData.RigidTransform(103).axis = [1.5035528878338074e-14 1.5341542055832761e-14 -1];
smiData.RigidTransform(103).ID = 'AssemblyGround[SecondJoint:1:Assembly1:4]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(104).translation = [-29.999999999999893 213.27283219299929 282.85364452999858];  % mm
smiData.RigidTransform(104).angle = 2.0943951023931944;  % rad
smiData.RigidTransform(104).axis = [-0.5773502691896254 -0.57735026918962662 0.5773502691896254];
smiData.RigidTransform(104).ID = 'AssemblyGround[SecondJoint:1:pcb:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(105).translation = [-97.849911014215138 -259.28563906547009 18.902365401480807];  % mm
smiData.RigidTransform(105).angle = 1.5707963267948584;  % rad
smiData.RigidTransform(105).axis = [2.9499805163474779e-14 1.3568407569801403e-28 -1];
smiData.RigidTransform(105).ID = 'AssemblyGround[SecondJoint:1:9. Fan:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(106).translation = [-97.849911014230486 -31.902118947467883 246.10491305247888];  % mm
smiData.RigidTransform(106).angle = 1.5707963267948595;  % rad
smiData.RigidTransform(106).axis = [3.1441863635909196e-14 1.7986028639039071e-28 -1];
smiData.RigidTransform(106).ID = 'AssemblyGround[SecondJoint:1:9. Fan:2]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(107).translation = [-97.84991101423185 197.24509418160309 41.273663107256766];  % mm
smiData.RigidTransform(107).angle = 3.0141246491451312;  % rad
smiData.RigidTransform(107).axis = [-0.70566527177063743 -0.70566527177063876 -0.0638204389967892];
smiData.RigidTransform(107).ID = 'AssemblyGround[SecondJoint:1:9. Fan:3]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(108).translation = [-97.849911014214513 -28.097881052542419 -186.10491305348776];  % mm
smiData.RigidTransform(108).angle = 3.1415926535897931;  % rad
smiData.RigidTransform(108).axis = [-0.70710678118653414 -0.7071067811865609 -2.5279688021866792e-14];
smiData.RigidTransform(108).ID = 'AssemblyGround[SecondJoint:1:9. Fan:4]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(109).translation = [-95.218668925621373 34.483408646141775 -14.219395121824654];  % mm
smiData.RigidTransform(109).angle = 1.6633520326217648;  % rad
smiData.RigidTransform(109).axis = [0.29086799413123759 -0.91147771227835483 -0.29086799413116393];
smiData.RigidTransform(109).ID = 'AssemblyGround[FirstJoint:1:shaft:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(110).translation = [-22.771762110286833 -39.904172494632078 22.357719028405327];  % mm
smiData.RigidTransform(110).angle = 1.7288043484117512;  % rad
smiData.RigidTransform(110).axis = [-0.85327820066275062 0.36872504137482914 0.36872504137482875];
smiData.RigidTransform(110).ID = 'AssemblyGround[FirstJoint:1:Encoder:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(111).translation = [-30.000000000000018 84.499999999999943 32.999999999999972];  % mm
smiData.RigidTransform(111).angle = 1.570796326794897;  % rad
smiData.RigidTransform(111).axis = [1 -5.3396440708162308e-16 -6.1723113392850667e-16];
smiData.RigidTransform(111).ID = 'AssemblyGround[FirstJoint:1:plummer blockPowe:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(112).translation = [-30.000000000000053 15.499999999999972 33.000000000000007];  % mm
smiData.RigidTransform(112).angle = 1.570796326794897;  % rad
smiData.RigidTransform(112).axis = [1 -6.7277681319908118e-17 -4.6718432815709286e-17];
smiData.RigidTransform(112).ID = 'AssemblyGround[FirstJoint:1:plummer blockPowe:2]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(113).translation = [-53.999999999999986 70.999999999996163 0.99999999999901945];  % mm
smiData.RigidTransform(113).angle = 1.570796326794897;  % rad
smiData.RigidTransform(113).axis = [-1 -0 -0];
smiData.RigidTransform(113).ID = 'AssemblyGround[FirstJoint:1:Holder Tube-R8:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(114).translation = [-20.000000000000018 70.999999999999929 1.0000000000000497];  % mm
smiData.RigidTransform(114).angle = 1.570796326794945;  % rad
smiData.RigidTransform(114).axis = [-1 0 0];
smiData.RigidTransform(114).ID = 'AssemblyGround[FirstJoint:1:Holder Tube-R8:2]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(115).translation = [-60.000000000000142 99.999999999999943 3.5527136788005009e-14];  % mm
smiData.RigidTransform(115).angle = 1.5707963267948966;  % rad
smiData.RigidTransform(115).axis = [0 0 1];
smiData.RigidTransform(115).ID = 'AssemblyGround[FirstJoint:1:interplate:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(116).translation = [-2.5000000000000711 77.999999999999957 6.0000000000000142];  % mm
smiData.RigidTransform(116).angle = 1.570796326794897;  % rad
smiData.RigidTransform(116).axis = [0 0 1];
smiData.RigidTransform(116).ID = 'AssemblyGround[FirstJoint:1:plateplummer:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(117).translation = [-2.5000000000000533 8.9999999999999858 6.0000000000000497];  % mm
smiData.RigidTransform(117).angle = 1.5707963267948959;  % rad
smiData.RigidTransform(117).axis = [0 0 1];
smiData.RigidTransform(117).ID = 'AssemblyGround[FirstJoint:1:plateplummer:2]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(118).translation = [-60.000000000000568 23.500000000000014 3.5527136788005009e-14];  % mm
smiData.RigidTransform(118).angle = 3.1415926535897931;  % rad
smiData.RigidTransform(118).axis = [-0.70710678118654635 0.70710678118654868 1.7678873094359646e-15];
smiData.RigidTransform(118).ID = 'AssemblyGround[FirstJoint:1:plateencoder:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(119).translation = [-30.000000000000036 -10.000000000000266 33.000000000000043];  % mm
smiData.RigidTransform(119).angle = 2.9924303474770402;  % rad
smiData.RigidTransform(119).axis = [-8.367341822960854e-17 1 -2.7802479794097924e-17];
smiData.RigidTransform(119).ID = 'AssemblyGround[FirstJoint:1:MOTOR COUPLER CONNECTOR (1):1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(120).translation = [-30.000000000000835 -26.50000000000027 13.750000000000107];  % mm
smiData.RigidTransform(120).angle = 3.1415926535897931;  % rad
smiData.RigidTransform(120).axis = [0 -0.70710678118654757 0.70710678118654746];
smiData.RigidTransform(120).ID = 'AssemblyGround[FirstJoint:1:Joint1C_1:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(121).translation = [-27.750000000000909 -26.500000000000263 -8.9999999999999858];  % mm
smiData.RigidTransform(121).angle = 1.5707963267948966;  % rad
smiData.RigidTransform(121).axis = [-1.2031094302952846e-16 -1 -1.2031094302953792e-16];
smiData.RigidTransform(121).ID = 'AssemblyGround[FirstJoint:1:2020RightAngle:1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(122).translation = [-49.250000000000824 -26.500000000000263 -8.9999999999999858];  % mm
smiData.RigidTransform(122).angle = 1.5707963267948966;  % rad
smiData.RigidTransform(122).axis = [-1.2031094302952856e-16 -1 -1.2031094302953171e-16];
smiData.RigidTransform(122).ID = 'AssemblyGround[FirstJoint:1:2020RightAngle:2]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(123).translation = [-299.99999999999761 3.5702535027231623e-13 -2.0989354541553078e-14];  % mm
smiData.RigidTransform(123).angle = 1.5707963267948917;  % rad
smiData.RigidTransform(123).axis = [1 -4.9586666372933088e-16 -7.134660397472151e-16];
smiData.RigidTransform(123).ID = 'SixDofRigidTransform[Base_V2:1]';


%============= Solid =============%
%Center of Mass (CoM) %Moments of Inertia (MoI) %Product of Inertia (PoI)

%Initialize the Solid structure array by filling in null values.
smiData.Solid(34).mass = 0.0;
smiData.Solid(34).CoM = [0.0 0.0 0.0];
smiData.Solid(34).MoI = [0.0 0.0 0.0];
smiData.Solid(34).PoI = [0.0 0.0 0.0];
smiData.Solid(34).color = [0.0 0.0 0.0];
smiData.Solid(34).opacity = 0.0;
smiData.Solid(34).ID = '';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(1).mass = 0.087468196937146858;  % lbm
smiData.Solid(1).CoM = [-0.010823836367861002 0.018131142622072476 3.5649305084762877];  % mm
smiData.Solid(1).MoI = [4.2715539311880288 9.0914032402824905 12.38704650918068];  % lbm*mm^2
smiData.Solid(1).PoI = [-0.00046078053964253036 0.0026289746112259332 -0.014267420532726645];  % lbm*mm^2
smiData.Solid(1).color = [0.74901960784313726 0.74901960784313726 0.74901960784313726];
smiData.Solid(1).opacity = 1;
smiData.Solid(1).ID = 'FlangedBearing8mm.ipt_{5F349C77-49F0-230C-02D6-73BA8E2439C9}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(2).mass = 4.2192480112728301;  % kg
smiData.Solid(2).CoM = [150.00000000000085 -149.99999999999997 2.9999999999999964];  % mm
smiData.Solid(2).MoI = [31495.257697003974 31526.941414147939 62996.883623084286];  % kg*mm^2
smiData.Solid(2).PoI = [-3.2741809263825413e-12 -4.729372449219227e-12 -2.3283064365386964e-11];  % kg*mm^2
smiData.Solid(2).color = [0.74901960784313726 0.74901960784313726 0.74901960784313726];
smiData.Solid(2).opacity = 1;
smiData.Solid(2).ID = 'BaseC_1.ipt_{5D9482F1-44C0-2241-E576-83AD39A4D9FC}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(3).mass = 0.053048651337125177;  % kg
smiData.Solid(3).CoM = [41.50000000000076 90.000000000000341 1.5];  % mm
smiData.Solid(3).MoI = [142.83640828715806 30.41132378445036 173.16815909460266];  % kg*mm^2
smiData.Solid(3).PoI = [0 0 -1.1368683772161603e-13];  % kg*mm^2
smiData.Solid(3).color = [0.74901960784313726 0.74901960784313726 0.74901960784313726];
smiData.Solid(3).opacity = 1;
smiData.Solid(3).ID = 'BaseC_2.ipt_{48335279-46D5-D588-54F7-FEB7AB736D98}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(4).mass = 0.047438347715385666;  % kg
smiData.Solid(4).CoM = [38.07080750127691 88.583849974973305 1.5];  % mm
smiData.Solid(4).MoI = [126.55355523610829 23.341268646471086 149.82366636100633];  % kg*mm^2
smiData.Solid(4).PoI = [0 0 -0.20629628698297892];  % kg*mm^2
smiData.Solid(4).color = [0.74901960784313726 0.74901960784313726 0.74901960784313726];
smiData.Solid(4).opacity = 1;
smiData.Solid(4).ID = 'BaseC_4.ipt_{48335279-46D5-D588-54F7-FEB7AB736D98}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(5).mass = 0.050547770671607872;  % kg
smiData.Solid(5).CoM = [41.500000000078892 92.24274859592964 1.5000000000000009];  % mm
smiData.Solid(5).MoI = [137.42712131961318 30.285999468948273 167.63729913255392];  % kg*mm^2
smiData.Solid(5).PoI = [0 0 1.8678747437661514e-10];  % kg*mm^2
smiData.Solid(5).color = [0.74901960784313726 0.74901960784313726 0.74901960784313726];
smiData.Solid(5).opacity = 1;
smiData.Solid(5).ID = 'BaseC_3.ipt_{48335279-46D5-D588-54F7-FEB7AB736D98}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(6).mass = 0.1130704440110195;  % kg
smiData.Solid(6).CoM = [-12.490656055849367 -1.7928160124473922 -9.0619125661417037];  % mm
smiData.Solid(6).MoI = [23.254977091940489 23.171394468650274 20.863754001217359];  % kg*mm^2
smiData.Solid(6).PoI = [0.25080991068017405 0.22400334072167141 -0.39660959127175172];  % kg*mm^2
smiData.Solid(6).color = [0.99607843137254903 0.99607843137254903 1];
smiData.Solid(6).opacity = 1;
smiData.Solid(6).ID = 'Encoder.ipt_{382EE0F2-4399-CFD0-9ACE-23AFC2C8F191}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(7).mass = 0.012427864726920869;  % kg
smiData.Solid(7).CoM = [-0.00012127946093956161 -0.00090599626235957444 0.000162361684031405];  % mm
smiData.Solid(7).MoI = [0.56275399266855308 0.2801720807124003 0.54700070955686952];  % kg*mm^2
smiData.Solid(7).PoI = [-3.0505250952901861e-05 -6.0748194535635073e-06 -7.5894048037355366e-06];  % kg*mm^2
smiData.Solid(7).color = [0.51372549019607838 0.34509803921568627 0.77254901960784317];
smiData.Solid(7).opacity = 1;
smiData.Solid(7).ID = 'MOTOR COUPLER CONNECTOR (1).ipt_{926813CD-46B3-7260-4FCA-64802166157E}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(8).mass = 0.14613913659453229;  % lbm
smiData.Solid(8).CoM = [112.56273339944828 354.52101755250231 195.68516236721652];  % mm
smiData.Solid(8).MoI = [78.280935519058247 27.940439415180315 94.069004699879642];  % lbm*mm^2
smiData.Solid(8).PoI = [1.2127008538022044e-06 2.698433562052618e-07 -1.5065960977092963e-06];  % lbm*mm^2
smiData.Solid(8).color = [0.99607843137254903 0.99607843137254903 1];
smiData.Solid(8).opacity = 1;
smiData.Solid(8).ID = 'BaseC_6.ipt_{D2F6E322-49B6-F776-5A8C-FE88F5739DE6}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(9).mass = 0.024011093661440743;  % kg
smiData.Solid(9).CoM = [1.1523307561043568e-10 -13.918724824064014 3];  % mm
smiData.Solid(9).MoI = [22.350098676375893 3.2837599961639325 25.48979211057118];  % kg*mm^2
smiData.Solid(9).PoI = [0 0 1.2456921240839855e-11];  % kg*mm^2
smiData.Solid(9).color = [0.74901960784313726 0.74901960784313726 0.74901960784313726];
smiData.Solid(9).opacity = 1;
smiData.Solid(9).ID = 'BaseC_7.ipt_{28708637-45C2-3567-D142-7BA9717EAC9F}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(10).mass = 0.18581607060105246;  % lbm
smiData.Solid(10).CoM = [-3.5729061915033549e-11 0 -38.500000000000007];  % mm
smiData.Solid(10).MoI = [492.49908896893862 492.49908897329675 14.759565298837538];  % lbm*mm^2
smiData.Solid(10).PoI = [0 0 0];  % lbm*mm^2
smiData.Solid(10).color = [0 0 0];
smiData.Solid(10).opacity = 1;
smiData.Solid(10).ID = '20x20mm V-Slot.ipt_{E2F57335-4498-05EA-8AF8-3597E978DFFD}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(11).mass = 0.024702412853771748;  % kg
smiData.Solid(11).CoM = [20.000807187818815 49.32135074904366 3];  % mm
smiData.Solid(11).MoI = [16.843792798220715 3.4459730990084902 20.141551420106577];  % kg*mm^2
smiData.Solid(11).PoI = [0 0 6.642040624171841e-05];  % kg*mm^2
smiData.Solid(11).color = [0.74901960784313726 0.74901960784313726 0.74901960784313726];
smiData.Solid(11).opacity = 1;
smiData.Solid(11).ID = 'BaseC_5.ipt_{48335279-46D5-D588-54F7-FEB7AB736D98}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(12).mass = 0.020348547641043383;  % kg
smiData.Solid(12).CoM = [38.000000000004349 -33.499999999998046 1.4999999999999991];  % mm
smiData.Solid(12).MoI = [11.694321347522116 8.3403151382268561 20.004113664287424];  % kg*mm^2
smiData.Solid(12).PoI = [0 0 0];  % kg*mm^2
smiData.Solid(12).color = [0.74901960784313726 0.74901960784313726 0.74901960784313726];
smiData.Solid(12).opacity = 1;
smiData.Solid(12).ID = 'BaseC_8.ipt_{96AD17E9-4129-33DB-12E6-4CB90BFC3604}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(13).mass = 0.012719080233195458;  % kg
smiData.Solid(13).CoM = [19.250000000008281 23.893043264491482 3];  % mm
smiData.Solid(13).MoI = [2.5257545317059824 1.6193205609021968 4.0687606112090053];  % kg*mm^2
smiData.Solid(13).PoI = [0 0 -3.311129148642067e-13];  % kg*mm^2
smiData.Solid(13).color = [0.74901960784313726 0.74901960784313726 0.74901960784313726];
smiData.Solid(13).opacity = 1;
smiData.Solid(13).ID = 'BaseC_9.ipt_{5B810C35-4687-F900-9091-64998421F767}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(14).mass = 0.0041312509378951022;  % kg
smiData.Solid(14).CoM = [-3.0000303706914453 6.0000303706914639 -8.5000000000000053];  % mm
smiData.Solid(14).MoI = [0.27656034345583891 0.27656034345583891 0.31431326241706981];  % kg*mm^2
smiData.Solid(14).PoI = [0 0 -0.083658960716714095];  % kg*mm^2
smiData.Solid(14).color = [0.99607843137254903 0.99607843137254903 1];
smiData.Solid(14).opacity = 1;
smiData.Solid(14).ID = '2020RightAngle.ipt_{95D018C0-48E7-D16C-D40F-88B34A7B78E1}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(15).mass = 0.033576191735608454;  % kg
smiData.Solid(15).CoM = [0.00059385789885420736 15.095038885065385 3.0000000000000009];  % mm
smiData.Solid(15).MoI = [41.049186779259436 4.6607758101191905 45.50850543896496];  % kg*mm^2
smiData.Solid(15).PoI = [0 0 0.00037006136335628064];  % kg*mm^2
smiData.Solid(15).color = [0.80000000000000004 0.80000000000000004 0.80000000000000004];
smiData.Solid(15).opacity = 0.46000000834465027;
smiData.Solid(15).ID = 'gard1.ipt_{B5228D04-45D3-71CC-8EA3-00B474682E43}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(16).mass = 0.018060437749492814;  % lbm
smiData.Solid(16).CoM = [-208.55899924599996 66.706469546396121 203.89546876806281];  % mm
smiData.Solid(16).MoI = [5.4273924244192147 9.0745866901497667 4.2024518541914331];  % lbm*mm^2
smiData.Solid(16).PoI = [-0.45870089486058002 4.0101851879604069e-13 0];  % lbm*mm^2
smiData.Solid(16).color = [0.92156862745098034 0.92156862745098034 0.92156862745098034];
smiData.Solid(16).opacity = 1;
smiData.Solid(16).ID = 'guard 2.ipt_{B5BC636F-4B14-C6EC-7885-A4822A147EDA}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(17).mass = 0.016220483760183872;  % lbm
smiData.Solid(17).CoM = [-208.55899924600004 2.855392424403318 200.61362902561552];  % mm
smiData.Solid(17).MoI = [3.6888672942117555 7.1050954247259845 3.9427635922266395];  % lbm*mm^2
smiData.Solid(17).PoI = [0.37038904508427811 0 0];  % lbm*mm^2
smiData.Solid(17).color = [0.92156862745098034 0.92156862745098034 0.92156862745098034];
smiData.Solid(17).opacity = 1;
smiData.Solid(17).ID = 'guard3.ipt_{D734EBDB-4E93-1D37-5A96-598A99B66C43}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(18).mass = 1.7016701556621572;  % lbm
smiData.Solid(18).CoM = [108.65500654070003 349.01557515609505 301.35391830956365];  % mm
smiData.Solid(18).MoI = [28461.612204311419 28461.260316444332 56912.662498348676];  % lbm*mm^2
smiData.Solid(18).PoI = [-8.5298243021993034e-07 -2.6558975277639218e-07 0.68690443282259128];  % lbm*mm^2
smiData.Solid(18).color = [0.64313725490196083 0.52156862745098043 0.3843137254901961];
smiData.Solid(18).opacity = 1;
smiData.Solid(18).ID = 'Assembly231015Kerangka Bawah 1.ipt_{CCBDE6AE-47EE-FAEA-B625-3AADA3A8BF8A}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(19).mass = 0.02376639381274484;  % kg
smiData.Solid(19).CoM = [7.0046101285590385 13.972810116040682 -21.057207032497701];  % mm
smiData.Solid(19).MoI = [3.96817444585372 2.0327948397528814 2.7618596397831761];  % kg*mm^2
smiData.Solid(19).PoI = [0.020452913583532961 -5.0784737823050815e-06 0.00050211316562815962];  % kg*mm^2
smiData.Solid(19).color = [0.99607843137254903 0.99607843137254903 1];
smiData.Solid(19).opacity = 1;
smiData.Solid(19).ID = 'Holder Tube-R8.ipt_{9EC99A22-4B73-B7C7-F88A-D88D0E54B488}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(20).mass = 0.050511783321476267;  % kg
smiData.Solid(20).CoM = [-13.700000000752748 9.3000000001825516 -65];  % mm
smiData.Solid(20).MoI = [71.339475321783411 71.339475278704327 0.40409424499538887];  % kg*mm^2
smiData.Solid(20).PoI = [0 0 -1.1086967788287438e-08];  % kg*mm^2
smiData.Solid(20).color = [0.74509803921568629 0.73725490196078436 0.72941176470588232];
smiData.Solid(20).opacity = 1;
smiData.Solid(20).ID = 'shaft.ipt_{87D27D31-4E9F-E5A0-BD4B-9787BB547A48}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(21).mass = 0.099418568769390342;  % kg
smiData.Solid(21).CoM = [243.27222432701021 251.31653371799467 12.000000000000048];  % mm
smiData.Solid(21).MoI = [34.732290287029898 34.73229028515707 59.920397970327755];  % kg*mm^2
smiData.Solid(21).PoI = [0 -9.0949470177292829e-14 -7.2759576141834263e-13];  % kg*mm^2
smiData.Solid(21).color = [0.80000000000000004 0.80000000000000004 0.80000000000000004];
smiData.Solid(21).opacity = 0.46000000834465027;
smiData.Solid(21).ID = 'Part15.ipt_{8C7FA10E-4B83-BE04-A9F3-B3A515BAA124}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(22).mass = 0.054664016340312108;  % kg
smiData.Solid(22).CoM = [335.98010353241546 349.11544490198946 319.81336914593703];  % mm
smiData.Solid(22).MoI = [5.0634204967791447 5.0795904471335236 4.8536671662499424];  % kg*mm^2
smiData.Solid(22).PoI = [-0.0062937059097748719 -0.0034446209087036551 0.0048661825087037867];  % kg*mm^2
smiData.Solid(22).color = [1 1 1];
smiData.Solid(22).opacity = 1;
smiData.Solid(22).ID = 'Part1.ipt_{32F25752-45A1-049A-BF84-4A8A6860CD65}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(23).mass = 0.079321469189285454;  % kg
smiData.Solid(23).CoM = [335.94929074807328 349.10204007198422 351.25391831100001];  % mm
smiData.Solid(23).MoI = [314.45986498256684 314.45971637009063 628.80059914886942];  % kg*mm^2
smiData.Solid(23).PoI = [2.9103830456733705e-12 0 -1.3758399290964006e-07];  % kg*mm^2
smiData.Solid(23).color = [0.019607843137254902 0.019607843137254902 0.019607843137254902];
smiData.Solid(23).opacity = 1;
smiData.Solid(23).ID = 'Part16.ipt_{1C847C5B-4F01-A010-1A1C-9787CD0BE53C}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(24).mass = 0.059825286597128075;  % kg
smiData.Solid(24).CoM = [335.94929075710348 349.10204014839854 312.25391831100006];  % mm
smiData.Solid(24).MoI = [265.24402992518151 265.24387810229382 530.39817009758258];  % kg*mm^2
smiData.Solid(24).PoI = [7.2759576141834263e-13 7.2759576141834263e-13 1.0229996405541897e-08];  % kg*mm^2
smiData.Solid(24).color = [0.019607843137254902 0.019607843137254902 0.019607843137254902];
smiData.Solid(24).opacity = 1;
smiData.Solid(24).ID = 'Part17.ipt_{F6E24D45-4DE3-78F4-392A-42A76E3EA430}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(25).mass = 0.008074162612528895;  % kg
smiData.Solid(25).CoM = [-20.408483583399175 204.22668790605491 1];  % mm
smiData.Solid(25).MoI = [0.81126688408303371 0.81615484196850252 1.622038950976548];  % kg*mm^2
smiData.Solid(25).PoI = [0 0 -0.00074719966977454533];  % kg*mm^2
smiData.Solid(25).color = [1 1 1];
smiData.Solid(25).opacity = 1;
smiData.Solid(25).ID = 'Part18.ipt_{F6511B55-4813-9AD8-2395-A88341D8779C}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(26).mass = 0.00091729708212200394;  % lbm
smiData.Solid(26).CoM = [9.9999317125895129 -6.422936348998667e-05 32.251917322879237];  % mm
smiData.Solid(26).MoI = [0.37340984723604848 0.37340984183809994 0.0026733085560911958];  % lbm*mm^2
smiData.Solid(26).PoI = [-2.1064004672991085e-06 -2.1525627153076982e-06 -2.4107963491265009e-08];  % lbm*mm^2
smiData.Solid(26).color = [0.92156862745098034 0.92156862745098034 0.92156862745098034];
smiData.Solid(26).opacity = 1;
smiData.Solid(26).ID = 'spacers for prop.ipt_{A1C7810D-4A94-7573-3106-D78933689566}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(27).mass = 0.0061930801576453665;  % lbm
smiData.Solid(27).CoM = [9.9999999999992149 -3.1799318772523769e-12 29.909397724656827];  % mm
smiData.Solid(27).MoI = [0.48145124551333229 0.48145124490883284 0.024398334318280767];  % lbm*mm^2
smiData.Solid(27).PoI = [-3.2622311685885916e-13 -4.9187427696076868e-12 0];  % lbm*mm^2
smiData.Solid(27).color = [0.18823529411764706 0.52941176470588236 0.8901960784313725];
smiData.Solid(27).opacity = 1;
smiData.Solid(27).ID = 'Standoff M3 M-M H 45mm.ipt_{A1C7810D-4A94-7573-3106-D78933689566}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(28).mass = 0.089776664943108681;  % kg
smiData.Solid(28).CoM = [-243.27283219739223 252.85364453000011 3.000000000000036];  % mm
smiData.Solid(28).MoI = [39.860831565025002 39.860841791309944 79.183013366676462];  % kg*mm^2
smiData.Solid(28).PoI = [0 0 -2.1827872842550277e-12];  % kg*mm^2
smiData.Solid(28).color = [0.99607843137254903 0.99607843137254903 1];
smiData.Solid(28).opacity = 1;
smiData.Solid(28).ID = 'pcb.ipt_{BD040302-45C5-21A1-1352-B19ED5375FC7}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(29).mass = 3.6399662954847503;  % g
smiData.Solid(29).CoM = [-1.9920934624515687 0.41175456439650449 11.187595844963321];  % mm
smiData.Solid(29).MoI = [5176.0102576237696 5258.1701069323781 115.5013383398197];  % g*mm^2
smiData.Solid(29).PoI = [0 91.007873646458307 0];  % g*mm^2
smiData.Solid(29).color = [0.92156862745098034 0.92156862745098034 0.92156862745098034];
smiData.Solid(29).opacity = 1;
smiData.Solid(29).ID = '9. Fan.ipt_{16CA4D95-48DF-3BD5-4672-7BA68779F1BD}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(30).mass = 0.039974844444101383;  % kg
smiData.Solid(30).CoM = [0.0031607117218455916 -4.2182751566538625 0.084572403824351994];  % mm
smiData.Solid(30).MoI = [2.8813212548650795 6.1058371958515929 8.3740375046181761];  % kg*mm^2
smiData.Solid(30).PoI = [-0.013769440406681533 -0.00047825626881312739 -0.00053678515043929494];  % kg*mm^2
smiData.Solid(30).color = [0.35294117647058826 0.3843137254901961 0.40000000000000002];
smiData.Solid(30).opacity = 1;
smiData.Solid(30).ID = 'plummer blockPowe.ipt_{E631A359-401E-BB9D-A1D0-EEBF6B903153}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(31).mass = 0.041155684384695169;  % kg
smiData.Solid(31).CoM = [-49.999999999987708 -30.00000000000011 2.9999999999999987];  % mm
smiData.Solid(31).MoI = [12.361744144136184 34.593933613468067 46.708743651296047];  % kg*mm^2
smiData.Solid(31).PoI = [0 0 -7.9580786405131228e-14];  % kg*mm^2
smiData.Solid(31).color = [0.74901960784313726 0.74901960784313726 0.74901960784313726];
smiData.Solid(31).opacity = 1;
smiData.Solid(31).ID = 'interplate.ipt_{BC4F1CDB-4CF2-5640-0FFD-89A5E1B3FC4E}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(32).mass = 0.0093868821923475416;  % kg
smiData.Solid(32).CoM = [6.5000000000269083 27.499999999999986 6];  % mm
smiData.Solid(32).MoI = [2.3248086384176063 0.25438071112382371 2.3539041769250915];  % kg*mm^2
smiData.Solid(32).PoI = [0 0 0];  % kg*mm^2
smiData.Solid(32).color = [0.74901960784313726 0.74901960784313726 0.74901960784313726];
smiData.Solid(32).opacity = 1;
smiData.Solid(32).ID = 'plateplummer.ipt_{99759009-4789-E48B-5BF5-239F9F7B0399}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(33).mass = 0.02075418921277156;  % kg
smiData.Solid(33).CoM = [25.177221810974451 -29.999999999999993 3];  % mm
smiData.Solid(33).MoI = [6.2758376978712702 4.3544875914758538 10.505800154070494];  % kg*mm^2
smiData.Solid(33).PoI = [0 0 0];  % kg*mm^2
smiData.Solid(33).color = [0.74901960784313726 0.74901960784313726 0.74901960784313726];
smiData.Solid(33).opacity = 1;
smiData.Solid(33).ID = 'plateencoder.ipt_{80562987-41F1-39ED-8F39-6BA8E77D38E1}';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(34).mass = 0.017744120624879255;  % kg
smiData.Solid(34).CoM = [1.5591987896578895e-10 7.9261253642384091 2.9999999999999987];  % mm
smiData.Solid(34).MoI = [8.4162619119523434 2.3655505569197368 10.675347745122805];  % kg*mm^2
smiData.Solid(34).PoI = [0 0 7.2491976765448954e-11];  % kg*mm^2
smiData.Solid(34).color = [0.74901960784313726 0.74901960784313726 0.74901960784313726];
smiData.Solid(34).opacity = 1;
smiData.Solid(34).ID = 'Joint1C_1.ipt_{28708637-45C2-3567-D142-7BA9717EAC9F}';


%============= Joint =============%
%X Revolute Primitive (Rx) %Y Revolute Primitive (Ry) %Z Revolute Primitive (Rz)
%X Prismatic Primitive (Px) %Y Prismatic Primitive (Py) %Z Prismatic Primitive (Pz) %Spherical Primitive (S)
%Constant Velocity Primitive (CV) %Lead Screw Primitive (LS)
%Position Target (Pos)

%Initialize the RevoluteJoint structure array by filling in null values.
smiData.RevoluteJoint(2).Rz.Pos = 0.0;
smiData.RevoluteJoint(2).ID = '';

smiData.RevoluteJoint(1).Rz.Pos = 89.99999999999973;  % deg
smiData.RevoluteJoint(1).ID = '[FirstJoint:1:-:Base_V2:1]';

smiData.RevoluteJoint(2).Rz.Pos = 89.999999999999559;  % deg
smiData.RevoluteJoint(2).ID = '[SecondJoint:1:-:FirstJoint:1]';

