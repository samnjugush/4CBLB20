  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (robotarm_student_2021a_Ebox_P)
    ;%
      section.nData     = 247;
      section.data(247)  = dumData; %prealloc
      
	  ;% robotarm_student_2021a_Ebox_P.DiscreteDerivative_ICPrevScaled
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% robotarm_student_2021a_Ebox_P.DiscreteDerivative_ICPrevScal_p
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% robotarm_student_2021a_Ebox_P.DiscreteDerivative_ICPrevScal_i
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% robotarm_student_2021a_Ebox_P.CompareToConstant_const
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% robotarm_student_2021a_Ebox_P.DetectChange_vinit
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% robotarm_student_2021a_Ebox_P.Delays_Y0
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% robotarm_student_2021a_Ebox_P.Suck_Value
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% robotarm_student_2021a_Ebox_P.Blow_Value
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% robotarm_student_2021a_Ebox_P.RobotV_Y0
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% robotarm_student_2021a_Ebox_P.ConveyorV_Y0
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% robotarm_student_2021a_Ebox_P.VacuumV_Y0
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% robotarm_student_2021a_Ebox_P.Blowsuck_Y0
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% robotarm_student_2021a_Ebox_P.Objectdetectionmatrix_Value
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% robotarm_student_2021a_Ebox_P.Discreteintegrator_gainval
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 24;
	
	  ;% robotarm_student_2021a_Ebox_P.Discreteintegrator_IC
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 25;
	
	  ;% robotarm_student_2021a_Ebox_P.Gain1_Gain
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 26;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctintegrator3_P1_Size
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 27;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctintegrator3_P1
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 29;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctintegrator3_P2_Size
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 30;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctintegrator3_P2
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 32;
	
	  ;% robotarm_student_2021a_Ebox_P.Dct1lowpass_P1_Size
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 33;
	
	  ;% robotarm_student_2021a_Ebox_P.Dct1lowpass_P1
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 35;
	
	  ;% robotarm_student_2021a_Ebox_P.Dct1lowpass_P2_Size
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 36;
	
	  ;% robotarm_student_2021a_Ebox_P.Dct1lowpass_P2
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 38;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P1_Size
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 39;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P1
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 41;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P2_Size
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 42;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P2
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 44;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P3_Size
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 45;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P3
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 47;
	
	  ;% robotarm_student_2021a_Ebox_P.ReferenceRrad_Value
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 48;
	
	  ;% robotarm_student_2021a_Ebox_P.Gain_Gain
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 49;
	
	  ;% robotarm_student_2021a_Ebox_P.FeedfowardRV_Value
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 50;
	
	  ;% robotarm_student_2021a_Ebox_P.ReferenceXrad_Value
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 51;
	
	  ;% robotarm_student_2021a_Ebox_P.Gain1_Gain_o
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 52;
	
	  ;% robotarm_student_2021a_Ebox_P.FeedfowardXV_Value
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 53;
	
	  ;% robotarm_student_2021a_Ebox_P.ReferenceZrad_Value
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 54;
	
	  ;% robotarm_student_2021a_Ebox_P.Gain_Gain_l
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 55;
	
	  ;% robotarm_student_2021a_Ebox_P.FeedfowardZV_Value
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 56;
	
	  ;% robotarm_student_2021a_Ebox_P.Conveyorspeedmms_Value
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 57;
	
	  ;% robotarm_student_2021a_Ebox_P.Saturation_UpperSat
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 58;
	
	  ;% robotarm_student_2021a_Ebox_P.Saturation_LowerSat
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 59;
	
	  ;% robotarm_student_2021a_Ebox_P.ReferenceVacuumbar_Value
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 60;
	
	  ;% robotarm_student_2021a_Ebox_P.Gain1_Gain_b
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 61;
	
	  ;% robotarm_student_2021a_Ebox_P.Object_Value
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 62;
	
	  ;% robotarm_student_2021a_Ebox_P.Plot_Value
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 63;
	
	  ;% robotarm_student_2021a_Ebox_P.Stop_Value
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 64;
	
	  ;% robotarm_student_2021a_Ebox_P.Gain5_Gain
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 65;
	
	  ;% robotarm_student_2021a_Ebox_P.HomingRunningSwitch2_Threshold
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 66;
	
	  ;% robotarm_student_2021a_Ebox_P.HomingRunningSwitch1_Threshold
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 67;
	
	  ;% robotarm_student_2021a_Ebox_P.HomingRunningSwitch_Threshold
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 68;
	
	  ;% robotarm_student_2021a_Ebox_P.HomingRunningSwitch_Threshold_o
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 69;
	
	  ;% robotarm_student_2021a_Ebox_P.HomingRunningSwitch_Threshold_j
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 70;
	
	  ;% robotarm_student_2021a_Ebox_P.SFunction_P1_Size
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 71;
	
	  ;% robotarm_student_2021a_Ebox_P.SFunction_P1
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 73;
	
	  ;% robotarm_student_2021a_Ebox_P.SFunction_P2_Size
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 74;
	
	  ;% robotarm_student_2021a_Ebox_P.SFunction_P2
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 76;
	
	  ;% robotarm_student_2021a_Ebox_P.ec_Ebox_P1_Size
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 77;
	
	  ;% robotarm_student_2021a_Ebox_P.ec_Ebox_P1
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 79;
	
	  ;% robotarm_student_2021a_Ebox_P.Gain_Gain_p
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 80;
	
	  ;% robotarm_student_2021a_Ebox_P.Gain1_Gain_c
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 81;
	
	  ;% robotarm_student_2021a_Ebox_P.ec_Ebox_P1_Size_d
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 82;
	
	  ;% robotarm_student_2021a_Ebox_P.ec_Ebox_P1_e
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 84;
	
	  ;% robotarm_student_2021a_Ebox_P.Gain2_Gain
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 85;
	
	  ;% robotarm_student_2021a_Ebox_P.ec_Ebox_P1_Size_du
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 86;
	
	  ;% robotarm_student_2021a_Ebox_P.ec_Ebox_P1_i
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 88;
	
	  ;% robotarm_student_2021a_Ebox_P.HomingRunningSwitch_Threshold_d
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 89;
	
	  ;% robotarm_student_2021a_Ebox_P.Gain3_Gain
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 90;
	
	  ;% robotarm_student_2021a_Ebox_P.Gain6_Gain
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 91;
	
	  ;% robotarm_student_2021a_Ebox_P.Constant_Value
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 92;
	
	  ;% robotarm_student_2021a_Ebox_P.DiscreteTimeIntegrator_gainval
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 93;
	
	  ;% robotarm_student_2021a_Ebox_P.DiscreteTimeIntegrator_IC
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 94;
	
	  ;% robotarm_student_2021a_Ebox_P.Constant1_Value
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 95;
	
	  ;% robotarm_student_2021a_Ebox_P.DiscreteTimeIntegrator_gainva_b
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 96;
	
	  ;% robotarm_student_2021a_Ebox_P.Constant_Value_g
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 97;
	
	  ;% robotarm_student_2021a_Ebox_P.UnitDelay_InitialCondition
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 98;
	
	  ;% robotarm_student_2021a_Ebox_P.set_robot_calibration_r_Value
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 99;
	
	  ;% robotarm_student_2021a_Ebox_P.DiscreteTimeIntegrator_gainva_a
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 100;
	
	  ;% robotarm_student_2021a_Ebox_P.DiscreteTimeIntegrator_IC_i
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 101;
	
	  ;% robotarm_student_2021a_Ebox_P.Constant1_Value_c
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 102;
	
	  ;% robotarm_student_2021a_Ebox_P.DiscreteTimeIntegrator_gainva_i
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 103;
	
	  ;% robotarm_student_2021a_Ebox_P.Constant_Value_n
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 104;
	
	  ;% robotarm_student_2021a_Ebox_P.set_robot_calibration_x_Value
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 105;
	
	  ;% robotarm_student_2021a_Ebox_P.DiscreteTimeIntegrator_gainv_ip
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 106;
	
	  ;% robotarm_student_2021a_Ebox_P.DiscreteTimeIntegrator_IC_d
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 107;
	
	  ;% robotarm_student_2021a_Ebox_P.Constant1_Value_e
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 108;
	
	  ;% robotarm_student_2021a_Ebox_P.DiscreteTimeIntegrator_gainva_n
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 109;
	
	  ;% robotarm_student_2021a_Ebox_P.Constant_Value_p
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 110;
	
	  ;% robotarm_student_2021a_Ebox_P.set_robot_calibration_z_Value
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 111;
	
	  ;% robotarm_student_2021a_Ebox_P.EnableVentiel_Value
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 112;
	
	  ;% robotarm_student_2021a_Ebox_P.Constant1_Value_f
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 120;
	
	  ;% robotarm_student_2021a_Ebox_P.Gain_Gain_j
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 121;
	
	  ;% robotarm_student_2021a_Ebox_P.Gain_Gain_ph
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 122;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctintegrator_P1_Size
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 123;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctintegrator_P1
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 125;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctintegrator_P2_Size
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 126;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctintegrator_P2
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 128;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P1_Size_p
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 129;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P1_c
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 131;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P2_Size_p
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 132;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P2_i
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 134;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P3_Size_c
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 135;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P3_m
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 137;
	
	  ;% robotarm_student_2021a_Ebox_P.Dct1lowpass_P1_Size_f
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 138;
	
	  ;% robotarm_student_2021a_Ebox_P.Dct1lowpass_P1_m
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 140;
	
	  ;% robotarm_student_2021a_Ebox_P.Dct1lowpass_P2_Size_g
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 141;
	
	  ;% robotarm_student_2021a_Ebox_P.Dct1lowpass_P2_l
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 143;
	
	  ;% robotarm_student_2021a_Ebox_P.Saturation_UpperSat_i
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 144;
	
	  ;% robotarm_student_2021a_Ebox_P.Saturation_LowerSat_m
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 145;
	
	  ;% robotarm_student_2021a_Ebox_P.Gain_Gain_ju
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 146;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P1_Size_n
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 147;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P1_p
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 149;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P2_Size_b
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 150;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P2_o
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 152;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P3_Size_d
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 153;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P3_c
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 155;
	
	  ;% robotarm_student_2021a_Ebox_P.Dct1lowpass_P1_Size_p
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 156;
	
	  ;% robotarm_student_2021a_Ebox_P.Dct1lowpass_P1_d
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 158;
	
	  ;% robotarm_student_2021a_Ebox_P.Dct1lowpass_P2_Size_gi
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 159;
	
	  ;% robotarm_student_2021a_Ebox_P.Dct1lowpass_P2_n
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 161;
	
	  ;% robotarm_student_2021a_Ebox_P.Voltagemiddle_Value
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 162;
	
	  ;% robotarm_student_2021a_Ebox_P.Gain1_Gain_h
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 163;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctintegrator_P1_Size_c
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 164;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctintegrator_P1_h
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 166;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctintegrator_P2_Size_j
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 167;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctintegrator_P2_c
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 169;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P1_Size_ph
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 170;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P1_f
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 172;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P2_Size_l
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 173;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P2_p
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 175;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P3_Size_j
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 176;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P3_f
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 178;
	
	  ;% robotarm_student_2021a_Ebox_P.Dct1lowpass_P1_Size_m
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 179;
	
	  ;% robotarm_student_2021a_Ebox_P.Dct1lowpass_P1_do
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 181;
	
	  ;% robotarm_student_2021a_Ebox_P.Dct1lowpass_P2_Size_i
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 182;
	
	  ;% robotarm_student_2021a_Ebox_P.Dct1lowpass_P2_nr
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 184;
	
	  ;% robotarm_student_2021a_Ebox_P.Gain1_Gain_d
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 185;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P1_Size_b
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 186;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P1_j
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 188;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P2_Size_o
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 189;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P2_b
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 191;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P3_Size_a
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 192;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P3_g
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 194;
	
	  ;% robotarm_student_2021a_Ebox_P.Dct1lowpass_P1_Size_i
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 195;
	
	  ;% robotarm_student_2021a_Ebox_P.Dct1lowpass_P1_db
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 197;
	
	  ;% robotarm_student_2021a_Ebox_P.Dct1lowpass_P2_Size_j
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 198;
	
	  ;% robotarm_student_2021a_Ebox_P.Dct1lowpass_P2_ns
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 200;
	
	  ;% robotarm_student_2021a_Ebox_P.Saturation_UpperSat_k
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 201;
	
	  ;% robotarm_student_2021a_Ebox_P.Saturation_LowerSat_i
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 202;
	
	  ;% robotarm_student_2021a_Ebox_P.Saturation_UpperSat_j
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 203;
	
	  ;% robotarm_student_2021a_Ebox_P.Saturation_LowerSat_f
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 204;
	
	  ;% robotarm_student_2021a_Ebox_P.Gain_Gain_ll
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 205;
	
	  ;% robotarm_student_2021a_Ebox_P.Gain_Gain_d
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 206;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctintegrator_P1_Size_j
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 207;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctintegrator_P1_d
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 209;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctintegrator_P2_Size_n
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 210;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctintegrator_P2_f
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 212;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P1_Size_o
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 213;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P1_g
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 215;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P2_Size_o4
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 216;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P2_e
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 218;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P3_Size_l
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 219;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P3_mc
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 221;
	
	  ;% robotarm_student_2021a_Ebox_P.Dct1lowpass_P1_Size_g
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 222;
	
	  ;% robotarm_student_2021a_Ebox_P.Dct1lowpass_P1_a
	  section.data(165).logicalSrcIdx = 164;
	  section.data(165).dtTransOffset = 224;
	
	  ;% robotarm_student_2021a_Ebox_P.Dct1lowpass_P2_Size_p
	  section.data(166).logicalSrcIdx = 165;
	  section.data(166).dtTransOffset = 225;
	
	  ;% robotarm_student_2021a_Ebox_P.Dct1lowpass_P2_o
	  section.data(167).logicalSrcIdx = 166;
	  section.data(167).dtTransOffset = 227;
	
	  ;% robotarm_student_2021a_Ebox_P.Gain_Gain_pq
	  section.data(168).logicalSrcIdx = 167;
	  section.data(168).dtTransOffset = 228;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P1_Size_f
	  section.data(169).logicalSrcIdx = 168;
	  section.data(169).dtTransOffset = 229;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P1_h
	  section.data(170).logicalSrcIdx = 169;
	  section.data(170).dtTransOffset = 231;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P2_Size_d
	  section.data(171).logicalSrcIdx = 170;
	  section.data(171).dtTransOffset = 232;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P2_l
	  section.data(172).logicalSrcIdx = 171;
	  section.data(172).dtTransOffset = 234;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P3_Size_p
	  section.data(173).logicalSrcIdx = 172;
	  section.data(173).dtTransOffset = 235;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P3_l
	  section.data(174).logicalSrcIdx = 173;
	  section.data(174).dtTransOffset = 237;
	
	  ;% robotarm_student_2021a_Ebox_P.Dct1lowpass_P1_Size_d
	  section.data(175).logicalSrcIdx = 174;
	  section.data(175).dtTransOffset = 238;
	
	  ;% robotarm_student_2021a_Ebox_P.Dct1lowpass_P1_g
	  section.data(176).logicalSrcIdx = 175;
	  section.data(176).dtTransOffset = 240;
	
	  ;% robotarm_student_2021a_Ebox_P.Dct1lowpass_P2_Size_k
	  section.data(177).logicalSrcIdx = 176;
	  section.data(177).dtTransOffset = 241;
	
	  ;% robotarm_student_2021a_Ebox_P.Dct1lowpass_P2_f
	  section.data(178).logicalSrcIdx = 177;
	  section.data(178).dtTransOffset = 243;
	
	  ;% robotarm_student_2021a_Ebox_P.DiscreteTimeIntegrator_gainva_c
	  section.data(179).logicalSrcIdx = 178;
	  section.data(179).dtTransOffset = 244;
	
	  ;% robotarm_student_2021a_Ebox_P.DiscreteTimeIntegrator_IC_f
	  section.data(180).logicalSrcIdx = 179;
	  section.data(180).dtTransOffset = 245;
	
	  ;% robotarm_student_2021a_Ebox_P.Gain1_Gain_p
	  section.data(181).logicalSrcIdx = 180;
	  section.data(181).dtTransOffset = 246;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctintegrator3_P1_Size_e
	  section.data(182).logicalSrcIdx = 181;
	  section.data(182).dtTransOffset = 247;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctintegrator3_P1_e
	  section.data(183).logicalSrcIdx = 182;
	  section.data(183).dtTransOffset = 249;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctintegrator3_P2_Size_i
	  section.data(184).logicalSrcIdx = 183;
	  section.data(184).dtTransOffset = 250;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctintegrator3_P2_a
	  section.data(185).logicalSrcIdx = 184;
	  section.data(185).dtTransOffset = 252;
	
	  ;% robotarm_student_2021a_Ebox_P.Dct1lowpass_P1_Size_ph
	  section.data(186).logicalSrcIdx = 185;
	  section.data(186).dtTransOffset = 253;
	
	  ;% robotarm_student_2021a_Ebox_P.Dct1lowpass_P1_j
	  section.data(187).logicalSrcIdx = 186;
	  section.data(187).dtTransOffset = 255;
	
	  ;% robotarm_student_2021a_Ebox_P.Dct1lowpass_P2_Size_p0
	  section.data(188).logicalSrcIdx = 187;
	  section.data(188).dtTransOffset = 256;
	
	  ;% robotarm_student_2021a_Ebox_P.Dct1lowpass_P2_p
	  section.data(189).logicalSrcIdx = 188;
	  section.data(189).dtTransOffset = 258;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P1_Size_pu
	  section.data(190).logicalSrcIdx = 189;
	  section.data(190).dtTransOffset = 259;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P1_je
	  section.data(191).logicalSrcIdx = 190;
	  section.data(191).dtTransOffset = 261;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P2_Size_n
	  section.data(192).logicalSrcIdx = 191;
	  section.data(192).dtTransOffset = 262;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P2_m
	  section.data(193).logicalSrcIdx = 192;
	  section.data(193).dtTransOffset = 264;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P3_Size_f
	  section.data(194).logicalSrcIdx = 193;
	  section.data(194).dtTransOffset = 265;
	
	  ;% robotarm_student_2021a_Ebox_P.Dctleadlag_P3_i
	  section.data(195).logicalSrcIdx = 194;
	  section.data(195).dtTransOffset = 267;
	
	  ;% robotarm_student_2021a_Ebox_P.HomingRunningSwitch_Threshold_c
	  section.data(196).logicalSrcIdx = 195;
	  section.data(196).dtTransOffset = 268;
	
	  ;% robotarm_student_2021a_Ebox_P.Gain4_Gain
	  section.data(197).logicalSrcIdx = 196;
	  section.data(197).dtTransOffset = 269;
	
	  ;% robotarm_student_2021a_Ebox_P.Saturation1_UpperSat
	  section.data(198).logicalSrcIdx = 197;
	  section.data(198).dtTransOffset = 270;
	
	  ;% robotarm_student_2021a_Ebox_P.Saturation1_LowerSat
	  section.data(199).logicalSrcIdx = 198;
	  section.data(199).dtTransOffset = 271;
	
	  ;% robotarm_student_2021a_Ebox_P.Saturation_UpperSat_e
	  section.data(200).logicalSrcIdx = 199;
	  section.data(200).dtTransOffset = 272;
	
	  ;% robotarm_student_2021a_Ebox_P.Saturation_LowerSat_o
	  section.data(201).logicalSrcIdx = 200;
	  section.data(201).dtTransOffset = 273;
	
	  ;% robotarm_student_2021a_Ebox_P.Gain_Gain_n
	  section.data(202).logicalSrcIdx = 201;
	  section.data(202).dtTransOffset = 274;
	
	  ;% robotarm_student_2021a_Ebox_P.HomingRunningSwitch1_Threshol_k
	  section.data(203).logicalSrcIdx = 202;
	  section.data(203).dtTransOffset = 275;
	
	  ;% robotarm_student_2021a_Ebox_P.Saturation2_UpperSat
	  section.data(204).logicalSrcIdx = 203;
	  section.data(204).dtTransOffset = 276;
	
	  ;% robotarm_student_2021a_Ebox_P.Saturation2_LowerSat
	  section.data(205).logicalSrcIdx = 204;
	  section.data(205).dtTransOffset = 277;
	
	  ;% robotarm_student_2021a_Ebox_P.Saturation_UpperSat_g
	  section.data(206).logicalSrcIdx = 205;
	  section.data(206).dtTransOffset = 278;
	
	  ;% robotarm_student_2021a_Ebox_P.Saturation_LowerSat_k
	  section.data(207).logicalSrcIdx = 206;
	  section.data(207).dtTransOffset = 279;
	
	  ;% robotarm_student_2021a_Ebox_P.UnitDelay1_InitialCondition
	  section.data(208).logicalSrcIdx = 207;
	  section.data(208).dtTransOffset = 280;
	
	  ;% robotarm_student_2021a_Ebox_P.HomingRunningSwitch_Threshold_f
	  section.data(209).logicalSrcIdx = 208;
	  section.data(209).dtTransOffset = 281;
	
	  ;% robotarm_student_2021a_Ebox_P.Gain_Gain_lr
	  section.data(210).logicalSrcIdx = 209;
	  section.data(210).dtTransOffset = 282;
	
	  ;% robotarm_student_2021a_Ebox_P.ResetEncoderR_P1_Size
	  section.data(211).logicalSrcIdx = 210;
	  section.data(211).dtTransOffset = 283;
	
	  ;% robotarm_student_2021a_Ebox_P.ResetEncoderR_P1
	  section.data(212).logicalSrcIdx = 211;
	  section.data(212).dtTransOffset = 285;
	
	  ;% robotarm_student_2021a_Ebox_P.ResetEncoderR_P2_Size
	  section.data(213).logicalSrcIdx = 212;
	  section.data(213).dtTransOffset = 286;
	
	  ;% robotarm_student_2021a_Ebox_P.ResetEncoderR_P2
	  section.data(214).logicalSrcIdx = 213;
	  section.data(214).dtTransOffset = 288;
	
	  ;% robotarm_student_2021a_Ebox_P.LimitSpeed_RisingLim
	  section.data(215).logicalSrcIdx = 214;
	  section.data(215).dtTransOffset = 289;
	
	  ;% robotarm_student_2021a_Ebox_P.LimitSpeed_FallingLim
	  section.data(216).logicalSrcIdx = 215;
	  section.data(216).dtTransOffset = 290;
	
	  ;% robotarm_student_2021a_Ebox_P.LimitSpeed_IC
	  section.data(217).logicalSrcIdx = 216;
	  section.data(217).dtTransOffset = 291;
	
	  ;% robotarm_student_2021a_Ebox_P.TSamp_WtEt
	  section.data(218).logicalSrcIdx = 217;
	  section.data(218).dtTransOffset = 292;
	
	  ;% robotarm_student_2021a_Ebox_P.LimitAcceleration_RisingLim
	  section.data(219).logicalSrcIdx = 218;
	  section.data(219).dtTransOffset = 293;
	
	  ;% robotarm_student_2021a_Ebox_P.LimitAcceleration_FallingLim
	  section.data(220).logicalSrcIdx = 219;
	  section.data(220).dtTransOffset = 294;
	
	  ;% robotarm_student_2021a_Ebox_P.LimitAcceleration_IC
	  section.data(221).logicalSrcIdx = 220;
	  section.data(221).dtTransOffset = 295;
	
	  ;% robotarm_student_2021a_Ebox_P.ResetEncoderX_P1_Size
	  section.data(222).logicalSrcIdx = 221;
	  section.data(222).dtTransOffset = 296;
	
	  ;% robotarm_student_2021a_Ebox_P.ResetEncoderX_P1
	  section.data(223).logicalSrcIdx = 222;
	  section.data(223).dtTransOffset = 298;
	
	  ;% robotarm_student_2021a_Ebox_P.ResetEncoderX_P2_Size
	  section.data(224).logicalSrcIdx = 223;
	  section.data(224).dtTransOffset = 299;
	
	  ;% robotarm_student_2021a_Ebox_P.ResetEncoderX_P2
	  section.data(225).logicalSrcIdx = 224;
	  section.data(225).dtTransOffset = 301;
	
	  ;% robotarm_student_2021a_Ebox_P.LimitSpeed_RisingLim_d
	  section.data(226).logicalSrcIdx = 225;
	  section.data(226).dtTransOffset = 302;
	
	  ;% robotarm_student_2021a_Ebox_P.LimitSpeed_FallingLim_j
	  section.data(227).logicalSrcIdx = 226;
	  section.data(227).dtTransOffset = 303;
	
	  ;% robotarm_student_2021a_Ebox_P.LimitSpeed_IC_g
	  section.data(228).logicalSrcIdx = 227;
	  section.data(228).dtTransOffset = 304;
	
	  ;% robotarm_student_2021a_Ebox_P.TSamp_WtEt_h
	  section.data(229).logicalSrcIdx = 228;
	  section.data(229).dtTransOffset = 305;
	
	  ;% robotarm_student_2021a_Ebox_P.LimitAcceleration_RisingLim_c
	  section.data(230).logicalSrcIdx = 229;
	  section.data(230).dtTransOffset = 306;
	
	  ;% robotarm_student_2021a_Ebox_P.LimitAcceleration_FallingLim_m
	  section.data(231).logicalSrcIdx = 230;
	  section.data(231).dtTransOffset = 307;
	
	  ;% robotarm_student_2021a_Ebox_P.LimitAcceleration_IC_f
	  section.data(232).logicalSrcIdx = 231;
	  section.data(232).dtTransOffset = 308;
	
	  ;% robotarm_student_2021a_Ebox_P.ResetEncoderX_P1_Size_k
	  section.data(233).logicalSrcIdx = 232;
	  section.data(233).dtTransOffset = 309;
	
	  ;% robotarm_student_2021a_Ebox_P.ResetEncoderX_P1_j
	  section.data(234).logicalSrcIdx = 233;
	  section.data(234).dtTransOffset = 311;
	
	  ;% robotarm_student_2021a_Ebox_P.ResetEncoderX_P2_Size_k
	  section.data(235).logicalSrcIdx = 234;
	  section.data(235).dtTransOffset = 312;
	
	  ;% robotarm_student_2021a_Ebox_P.ResetEncoderX_P2_j
	  section.data(236).logicalSrcIdx = 235;
	  section.data(236).dtTransOffset = 314;
	
	  ;% robotarm_student_2021a_Ebox_P.LimitSpeed_RisingLim_m
	  section.data(237).logicalSrcIdx = 236;
	  section.data(237).dtTransOffset = 315;
	
	  ;% robotarm_student_2021a_Ebox_P.LimitSpeed_FallingLim_jw
	  section.data(238).logicalSrcIdx = 237;
	  section.data(238).dtTransOffset = 316;
	
	  ;% robotarm_student_2021a_Ebox_P.LimitSpeed_IC_j
	  section.data(239).logicalSrcIdx = 238;
	  section.data(239).dtTransOffset = 317;
	
	  ;% robotarm_student_2021a_Ebox_P.TSamp_WtEt_i
	  section.data(240).logicalSrcIdx = 239;
	  section.data(240).dtTransOffset = 318;
	
	  ;% robotarm_student_2021a_Ebox_P.LimitAcceleration_RisingLim_j
	  section.data(241).logicalSrcIdx = 240;
	  section.data(241).dtTransOffset = 319;
	
	  ;% robotarm_student_2021a_Ebox_P.LimitAcceleration_FallingLim_h
	  section.data(242).logicalSrcIdx = 241;
	  section.data(242).dtTransOffset = 320;
	
	  ;% robotarm_student_2021a_Ebox_P.LimitAcceleration_IC_j
	  section.data(243).logicalSrcIdx = 242;
	  section.data(243).dtTransOffset = 321;
	
	  ;% robotarm_student_2021a_Ebox_P.ResetEncoderConv_P1_Size
	  section.data(244).logicalSrcIdx = 243;
	  section.data(244).dtTransOffset = 322;
	
	  ;% robotarm_student_2021a_Ebox_P.ResetEncoderConv_P1
	  section.data(245).logicalSrcIdx = 244;
	  section.data(245).dtTransOffset = 324;
	
	  ;% robotarm_student_2021a_Ebox_P.ResetEncoderConv_P2_Size
	  section.data(246).logicalSrcIdx = 245;
	  section.data(246).dtTransOffset = 325;
	
	  ;% robotarm_student_2021a_Ebox_P.ResetEncoderConv_P2
	  section.data(247).logicalSrcIdx = 246;
	  section.data(247).dtTransOffset = 327;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% robotarm_student_2021a_Ebox_P.LEDRing_Y0
	  section.data(1).logicalSrcIdx = 247;
	  section.data(1).dtTransOffset = 0;
	
	  ;% robotarm_student_2021a_Ebox_P.Colorsetwithstringblackorwhite_
	  section.data(2).logicalSrcIdx = 248;
	  section.data(2).dtTransOffset = 1;
	
	  ;% robotarm_student_2021a_Ebox_P.Colorspecifiedin6hexdigitsrrggb
	  section.data(3).logicalSrcIdx = 249;
	  section.data(3).dtTransOffset = 2;
	
	  ;% robotarm_student_2021a_Ebox_P.StringConstant3_String
	  section.data(4).logicalSrcIdx = 250;
	  section.data(4).dtTransOffset = 3;
	
	  ;% robotarm_student_2021a_Ebox_P.StringConstant4_String
	  section.data(5).logicalSrcIdx = 251;
	  section.data(5).dtTransOffset = 4;
	
	  ;% robotarm_student_2021a_Ebox_P.StringConstant1_String
	  section.data(6).logicalSrcIdx = 252;
	  section.data(6).dtTransOffset = 5;
	
	  ;% robotarm_student_2021a_Ebox_P.ReadyGreen_String
	  section.data(7).logicalSrcIdx = 253;
	  section.data(7).dtTransOffset = 6;
	
	  ;% robotarm_student_2021a_Ebox_P.AirbagRed_String
	  section.data(8).logicalSrcIdx = 254;
	  section.data(8).dtTransOffset = 7;
	
	  ;% robotarm_student_2021a_Ebox_P.HomingOrange_String
	  section.data(9).logicalSrcIdx = 255;
	  section.data(9).dtTransOffset = 8;
	
	  ;% robotarm_student_2021a_Ebox_P.Delay_InitialCondition
	  section.data(10).logicalSrcIdx = 256;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% robotarm_student_2021a_Ebox_P.ManualSwitch_CurrentSetting
	  section.data(1).logicalSrcIdx = 257;
	  section.data(1).dtTransOffset = 0;
	
	  ;% robotarm_student_2021a_Ebox_P.ManualSwitch1_CurrentSetting
	  section.data(2).logicalSrcIdx = 258;
	  section.data(2).dtTransOffset = 1;
	
	  ;% robotarm_student_2021a_Ebox_P.Constant1_Value_b
	  section.data(3).logicalSrcIdx = 259;
	  section.data(3).dtTransOffset = 2;
	
	  ;% robotarm_student_2021a_Ebox_P.Constant_Value_c
	  section.data(4).logicalSrcIdx = 260;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (robotarm_student_2021a_Ebox_B)
    ;%
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% robotarm_student_2021a_Ebox_B.ec_Ebox_o2
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% robotarm_student_2021a_Ebox_B.ec_Ebox_o3
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 2;
	
	  ;% robotarm_student_2021a_Ebox_B.ec_Ebox_o1_h
	  section.data(3).logicalSrcIdx = 5;
	  section.data(3).dtTransOffset = 10;
	
	  ;% robotarm_student_2021a_Ebox_B.ec_Ebox_o2_o
	  section.data(4).logicalSrcIdx = 6;
	  section.data(4).dtTransOffset = 12;
	
	  ;% robotarm_student_2021a_Ebox_B.ec_Ebox_o3_p
	  section.data(5).logicalSrcIdx = 7;
	  section.data(5).dtTransOffset = 14;
	
	  ;% robotarm_student_2021a_Ebox_B.ec_Ebox_o1_o
	  section.data(6).logicalSrcIdx = 8;
	  section.data(6).dtTransOffset = 22;
	
	  ;% robotarm_student_2021a_Ebox_B.ec_Ebox_o2_p
	  section.data(7).logicalSrcIdx = 9;
	  section.data(7).dtTransOffset = 24;
	
	  ;% robotarm_student_2021a_Ebox_B.ec_Ebox_o3_j
	  section.data(8).logicalSrcIdx = 10;
	  section.data(8).dtTransOffset = 26;
	
	  ;% robotarm_student_2021a_Ebox_B.HomingRunningSwitch
	  section.data(9).logicalSrcIdx = 11;
	  section.data(9).dtTransOffset = 34;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% robotarm_student_2021a_Ebox_B.ManualSwitch1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 110;
      section.data(110)  = dumData; %prealloc
      
	  ;% robotarm_student_2021a_Ebox_B.SFunction
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% robotarm_student_2021a_Ebox_B.ec_Ebox_o1
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
	  ;% robotarm_student_2021a_Ebox_B.Gain3
	  section.data(3).logicalSrcIdx = 12;
	  section.data(3).dtTransOffset = 3;
	
	  ;% robotarm_student_2021a_Ebox_B.Gain6
	  section.data(4).logicalSrcIdx = 13;
	  section.data(4).dtTransOffset = 4;
	
	  ;% robotarm_student_2021a_Ebox_B.Constant1
	  section.data(5).logicalSrcIdx = 14;
	  section.data(5).dtTransOffset = 5;
	
	  ;% robotarm_student_2021a_Ebox_B.Sum
	  section.data(6).logicalSrcIdx = 15;
	  section.data(6).dtTransOffset = 6;
	
	  ;% robotarm_student_2021a_Ebox_B.set_robot_calibration_r
	  section.data(7).logicalSrcIdx = 16;
	  section.data(7).dtTransOffset = 7;
	
	  ;% robotarm_student_2021a_Ebox_B.Constant1_c
	  section.data(8).logicalSrcIdx = 17;
	  section.data(8).dtTransOffset = 8;
	
	  ;% robotarm_student_2021a_Ebox_B.Sum_a
	  section.data(9).logicalSrcIdx = 18;
	  section.data(9).dtTransOffset = 9;
	
	  ;% robotarm_student_2021a_Ebox_B.set_robot_calibration_x
	  section.data(10).logicalSrcIdx = 19;
	  section.data(10).dtTransOffset = 10;
	
	  ;% robotarm_student_2021a_Ebox_B.Constant1_k
	  section.data(11).logicalSrcIdx = 20;
	  section.data(11).dtTransOffset = 11;
	
	  ;% robotarm_student_2021a_Ebox_B.Sum_g
	  section.data(12).logicalSrcIdx = 21;
	  section.data(12).dtTransOffset = 12;
	
	  ;% robotarm_student_2021a_Ebox_B.set_robot_calibration_z
	  section.data(13).logicalSrcIdx = 22;
	  section.data(13).dtTransOffset = 13;
	
	  ;% robotarm_student_2021a_Ebox_B.Add1
	  section.data(14).logicalSrcIdx = 23;
	  section.data(14).dtTransOffset = 14;
	
	  ;% robotarm_student_2021a_Ebox_B.Assignment
	  section.data(15).logicalSrcIdx = 24;
	  section.data(15).dtTransOffset = 15;
	
	  ;% robotarm_student_2021a_Ebox_B.Gain
	  section.data(16).logicalSrcIdx = 25;
	  section.data(16).dtTransOffset = 23;
	
	  ;% robotarm_student_2021a_Ebox_B.Gain_c
	  section.data(17).logicalSrcIdx = 26;
	  section.data(17).dtTransOffset = 25;
	
	  ;% robotarm_student_2021a_Ebox_B.Dctintegrator
	  section.data(18).logicalSrcIdx = 27;
	  section.data(18).dtTransOffset = 26;
	
	  ;% robotarm_student_2021a_Ebox_B.Dctleadlag
	  section.data(19).logicalSrcIdx = 28;
	  section.data(19).dtTransOffset = 27;
	
	  ;% robotarm_student_2021a_Ebox_B.Dct1lowpass
	  section.data(20).logicalSrcIdx = 29;
	  section.data(20).dtTransOffset = 28;
	
	  ;% robotarm_student_2021a_Ebox_B.Saturation
	  section.data(21).logicalSrcIdx = 30;
	  section.data(21).dtTransOffset = 29;
	
	  ;% robotarm_student_2021a_Ebox_B.Gain_f
	  section.data(22).logicalSrcIdx = 31;
	  section.data(22).dtTransOffset = 30;
	
	  ;% robotarm_student_2021a_Ebox_B.Dctleadlag_j
	  section.data(23).logicalSrcIdx = 32;
	  section.data(23).dtTransOffset = 31;
	
	  ;% robotarm_student_2021a_Ebox_B.Dct1lowpass_n
	  section.data(24).logicalSrcIdx = 33;
	  section.data(24).dtTransOffset = 32;
	
	  ;% robotarm_student_2021a_Ebox_B.Gain1
	  section.data(25).logicalSrcIdx = 34;
	  section.data(25).dtTransOffset = 33;
	
	  ;% robotarm_student_2021a_Ebox_B.Dctintegrator_i
	  section.data(26).logicalSrcIdx = 35;
	  section.data(26).dtTransOffset = 34;
	
	  ;% robotarm_student_2021a_Ebox_B.Dctleadlag_n
	  section.data(27).logicalSrcIdx = 36;
	  section.data(27).dtTransOffset = 35;
	
	  ;% robotarm_student_2021a_Ebox_B.Dct1lowpass_f
	  section.data(28).logicalSrcIdx = 37;
	  section.data(28).dtTransOffset = 36;
	
	  ;% robotarm_student_2021a_Ebox_B.Product
	  section.data(29).logicalSrcIdx = 38;
	  section.data(29).dtTransOffset = 37;
	
	  ;% robotarm_student_2021a_Ebox_B.Gain1_p
	  section.data(30).logicalSrcIdx = 39;
	  section.data(30).dtTransOffset = 38;
	
	  ;% robotarm_student_2021a_Ebox_B.Dctleadlag_e
	  section.data(31).logicalSrcIdx = 40;
	  section.data(31).dtTransOffset = 39;
	
	  ;% robotarm_student_2021a_Ebox_B.Dct1lowpass_o
	  section.data(32).logicalSrcIdx = 41;
	  section.data(32).dtTransOffset = 40;
	
	  ;% robotarm_student_2021a_Ebox_B.Saturation_p
	  section.data(33).logicalSrcIdx = 42;
	  section.data(33).dtTransOffset = 41;
	
	  ;% robotarm_student_2021a_Ebox_B.Gain_j
	  section.data(34).logicalSrcIdx = 43;
	  section.data(34).dtTransOffset = 43;
	
	  ;% robotarm_student_2021a_Ebox_B.Gain_e
	  section.data(35).logicalSrcIdx = 44;
	  section.data(35).dtTransOffset = 45;
	
	  ;% robotarm_student_2021a_Ebox_B.Dctintegrator_g
	  section.data(36).logicalSrcIdx = 45;
	  section.data(36).dtTransOffset = 46;
	
	  ;% robotarm_student_2021a_Ebox_B.Dctleadlag_eg
	  section.data(37).logicalSrcIdx = 46;
	  section.data(37).dtTransOffset = 47;
	
	  ;% robotarm_student_2021a_Ebox_B.Dct1lowpass_ft
	  section.data(38).logicalSrcIdx = 47;
	  section.data(38).dtTransOffset = 48;
	
	  ;% robotarm_student_2021a_Ebox_B.Product_b
	  section.data(39).logicalSrcIdx = 48;
	  section.data(39).dtTransOffset = 49;
	
	  ;% robotarm_student_2021a_Ebox_B.Gain_i
	  section.data(40).logicalSrcIdx = 49;
	  section.data(40).dtTransOffset = 50;
	
	  ;% robotarm_student_2021a_Ebox_B.Dctleadlag_i
	  section.data(41).logicalSrcIdx = 50;
	  section.data(41).dtTransOffset = 51;
	
	  ;% robotarm_student_2021a_Ebox_B.Dct1lowpass_a
	  section.data(42).logicalSrcIdx = 51;
	  section.data(42).dtTransOffset = 52;
	
	  ;% robotarm_student_2021a_Ebox_B.DiscreteTimeIntegrator
	  section.data(43).logicalSrcIdx = 52;
	  section.data(43).dtTransOffset = 53;
	
	  ;% robotarm_student_2021a_Ebox_B.Gain1_n
	  section.data(44).logicalSrcIdx = 53;
	  section.data(44).dtTransOffset = 54;
	
	  ;% robotarm_student_2021a_Ebox_B.Dctintegrator3
	  section.data(45).logicalSrcIdx = 54;
	  section.data(45).dtTransOffset = 55;
	
	  ;% robotarm_student_2021a_Ebox_B.Dct1lowpass_p
	  section.data(46).logicalSrcIdx = 55;
	  section.data(46).dtTransOffset = 56;
	
	  ;% robotarm_student_2021a_Ebox_B.Dctleadlag_f
	  section.data(47).logicalSrcIdx = 56;
	  section.data(47).dtTransOffset = 57;
	
	  ;% robotarm_student_2021a_Ebox_B.Sum1
	  section.data(48).logicalSrcIdx = 57;
	  section.data(48).dtTransOffset = 58;
	
	  ;% robotarm_student_2021a_Ebox_B.Saturation_f
	  section.data(49).logicalSrcIdx = 58;
	  section.data(49).dtTransOffset = 59;
	
	  ;% robotarm_student_2021a_Ebox_B.Gain_n
	  section.data(50).logicalSrcIdx = 59;
	  section.data(50).dtTransOffset = 61;
	
	  ;% robotarm_student_2021a_Ebox_B.Saturation_h
	  section.data(51).logicalSrcIdx = 60;
	  section.data(51).dtTransOffset = 63;
	
	  ;% robotarm_student_2021a_Ebox_B.jogSpeed
	  section.data(52).logicalSrcIdx = 61;
	  section.data(52).dtTransOffset = 65;
	
	  ;% robotarm_student_2021a_Ebox_B.homeControllerEnabled
	  section.data(53).logicalSrcIdx = 62;
	  section.data(53).dtTransOffset = 66;
	
	  ;% robotarm_student_2021a_Ebox_B.resetEnc
	  section.data(54).logicalSrcIdx = 63;
	  section.data(54).dtTransOffset = 67;
	
	  ;% robotarm_student_2021a_Ebox_B.homingBusy
	  section.data(55).logicalSrcIdx = 64;
	  section.data(55).dtTransOffset = 68;
	
	  ;% robotarm_student_2021a_Ebox_B.Ready
	  section.data(56).logicalSrcIdx = 65;
	  section.data(56).dtTransOffset = 69;
	
	  ;% robotarm_student_2021a_Ebox_B.StopSim
	  section.data(57).logicalSrcIdx = 66;
	  section.data(57).dtTransOffset = 70;
	
	  ;% robotarm_student_2021a_Ebox_B.jogSpeed_f
	  section.data(58).logicalSrcIdx = 67;
	  section.data(58).dtTransOffset = 71;
	
	  ;% robotarm_student_2021a_Ebox_B.toPoint
	  section.data(59).logicalSrcIdx = 68;
	  section.data(59).dtTransOffset = 72;
	
	  ;% robotarm_student_2021a_Ebox_B.homeControllerEnabled_j
	  section.data(60).logicalSrcIdx = 69;
	  section.data(60).dtTransOffset = 73;
	
	  ;% robotarm_student_2021a_Ebox_B.resetEnc_j
	  section.data(61).logicalSrcIdx = 70;
	  section.data(61).dtTransOffset = 74;
	
	  ;% robotarm_student_2021a_Ebox_B.homingBusy_j
	  section.data(62).logicalSrcIdx = 71;
	  section.data(62).dtTransOffset = 75;
	
	  ;% robotarm_student_2021a_Ebox_B.airBagEnabled
	  section.data(63).logicalSrcIdx = 72;
	  section.data(63).dtTransOffset = 76;
	
	  ;% robotarm_student_2021a_Ebox_B.airBagRef
	  section.data(64).logicalSrcIdx = 73;
	  section.data(64).dtTransOffset = 77;
	
	  ;% robotarm_student_2021a_Ebox_B.controlEnabled
	  section.data(65).logicalSrcIdx = 74;
	  section.data(65).dtTransOffset = 78;
	
	  ;% robotarm_student_2021a_Ebox_B.Ready_c
	  section.data(66).logicalSrcIdx = 75;
	  section.data(66).dtTransOffset = 79;
	
	  ;% robotarm_student_2021a_Ebox_B.StopSim_n
	  section.data(67).logicalSrcIdx = 76;
	  section.data(67).dtTransOffset = 80;
	
	  ;% robotarm_student_2021a_Ebox_B.y
	  section.data(68).logicalSrcIdx = 77;
	  section.data(68).dtTransOffset = 81;
	
	  ;% robotarm_student_2021a_Ebox_B.jogSpeed_o
	  section.data(69).logicalSrcIdx = 78;
	  section.data(69).dtTransOffset = 82;
	
	  ;% robotarm_student_2021a_Ebox_B.toPoint_h
	  section.data(70).logicalSrcIdx = 79;
	  section.data(70).dtTransOffset = 83;
	
	  ;% robotarm_student_2021a_Ebox_B.homeControllerEnabled_f
	  section.data(71).logicalSrcIdx = 80;
	  section.data(71).dtTransOffset = 84;
	
	  ;% robotarm_student_2021a_Ebox_B.resetEnc_n
	  section.data(72).logicalSrcIdx = 81;
	  section.data(72).dtTransOffset = 85;
	
	  ;% robotarm_student_2021a_Ebox_B.homingBusy_d
	  section.data(73).logicalSrcIdx = 82;
	  section.data(73).dtTransOffset = 86;
	
	  ;% robotarm_student_2021a_Ebox_B.airBagEnabled_a
	  section.data(74).logicalSrcIdx = 83;
	  section.data(74).dtTransOffset = 87;
	
	  ;% robotarm_student_2021a_Ebox_B.airBagRef_p
	  section.data(75).logicalSrcIdx = 84;
	  section.data(75).dtTransOffset = 88;
	
	  ;% robotarm_student_2021a_Ebox_B.controlEnabled_b
	  section.data(76).logicalSrcIdx = 85;
	  section.data(76).dtTransOffset = 89;
	
	  ;% robotarm_student_2021a_Ebox_B.Ready_l
	  section.data(77).logicalSrcIdx = 86;
	  section.data(77).dtTransOffset = 90;
	
	  ;% robotarm_student_2021a_Ebox_B.StopSim_p
	  section.data(78).logicalSrcIdx = 87;
	  section.data(78).dtTransOffset = 91;
	
	  ;% robotarm_student_2021a_Ebox_B.jogSpeed_p
	  section.data(79).logicalSrcIdx = 88;
	  section.data(79).dtTransOffset = 92;
	
	  ;% robotarm_student_2021a_Ebox_B.toPoint_i
	  section.data(80).logicalSrcIdx = 89;
	  section.data(80).dtTransOffset = 93;
	
	  ;% robotarm_student_2021a_Ebox_B.homeControllerEnabled_i
	  section.data(81).logicalSrcIdx = 90;
	  section.data(81).dtTransOffset = 94;
	
	  ;% robotarm_student_2021a_Ebox_B.resetEnc_l
	  section.data(82).logicalSrcIdx = 91;
	  section.data(82).dtTransOffset = 95;
	
	  ;% robotarm_student_2021a_Ebox_B.homingBusy_n
	  section.data(83).logicalSrcIdx = 92;
	  section.data(83).dtTransOffset = 96;
	
	  ;% robotarm_student_2021a_Ebox_B.airBagEnabled_ab
	  section.data(84).logicalSrcIdx = 93;
	  section.data(84).dtTransOffset = 97;
	
	  ;% robotarm_student_2021a_Ebox_B.airBagRef_pn
	  section.data(85).logicalSrcIdx = 94;
	  section.data(85).dtTransOffset = 98;
	
	  ;% robotarm_student_2021a_Ebox_B.controlEnabled_e
	  section.data(86).logicalSrcIdx = 95;
	  section.data(86).dtTransOffset = 99;
	
	  ;% robotarm_student_2021a_Ebox_B.Ready_n
	  section.data(87).logicalSrcIdx = 96;
	  section.data(87).dtTransOffset = 100;
	
	  ;% robotarm_student_2021a_Ebox_B.StopSim_np
	  section.data(88).logicalSrcIdx = 97;
	  section.data(88).dtTransOffset = 101;
	
	  ;% robotarm_student_2021a_Ebox_B.y_j
	  section.data(89).logicalSrcIdx = 98;
	  section.data(89).dtTransOffset = 102;
	
	  ;% robotarm_student_2021a_Ebox_B.Selector2
	  section.data(90).logicalSrcIdx = 99;
	  section.data(90).dtTransOffset = 103;
	
	  ;% robotarm_student_2021a_Ebox_B.Selector
	  section.data(91).logicalSrcIdx = 100;
	  section.data(91).dtTransOffset = 112;
	
	  ;% robotarm_student_2021a_Ebox_B.Conveyorreferencemm
	  section.data(92).logicalSrcIdx = 101;
	  section.data(92).dtTransOffset = 115;
	
	  ;% robotarm_student_2021a_Ebox_B.Gain1_g
	  section.data(93).logicalSrcIdx = 102;
	  section.data(93).dtTransOffset = 116;
	
	  ;% robotarm_student_2021a_Ebox_B.Dctintegrator3_n
	  section.data(94).logicalSrcIdx = 103;
	  section.data(94).dtTransOffset = 117;
	
	  ;% robotarm_student_2021a_Ebox_B.Dct1lowpass_ab
	  section.data(95).logicalSrcIdx = 104;
	  section.data(95).dtTransOffset = 118;
	
	  ;% robotarm_student_2021a_Ebox_B.Dctleadlag_d
	  section.data(96).logicalSrcIdx = 105;
	  section.data(96).dtTransOffset = 119;
	
	  ;% robotarm_student_2021a_Ebox_B.SFunctionBuilder
	  section.data(97).logicalSrcIdx = 106;
	  section.data(97).dtTransOffset = 120;
	
	  ;% robotarm_student_2021a_Ebox_B.Sum_m
	  section.data(98).logicalSrcIdx = 107;
	  section.data(98).dtTransOffset = 121;
	
	  ;% robotarm_student_2021a_Ebox_B.SignalConversion2
	  section.data(99).logicalSrcIdx = 108;
	  section.data(99).dtTransOffset = 122;
	
	  ;% robotarm_student_2021a_Ebox_B.Sum4
	  section.data(100).logicalSrcIdx = 109;
	  section.data(100).dtTransOffset = 123;
	
	  ;% robotarm_student_2021a_Ebox_B.SignalConversion1
	  section.data(101).logicalSrcIdx = 110;
	  section.data(101).dtTransOffset = 124;
	
	  ;% robotarm_student_2021a_Ebox_B.Sum5
	  section.data(102).logicalSrcIdx = 111;
	  section.data(102).dtTransOffset = 125;
	
	  ;% robotarm_student_2021a_Ebox_B.SignalConversion
	  section.data(103).logicalSrcIdx = 112;
	  section.data(103).dtTransOffset = 126;
	
	  ;% robotarm_student_2021a_Ebox_B.Sum6
	  section.data(104).logicalSrcIdx = 113;
	  section.data(104).dtTransOffset = 127;
	
	  ;% robotarm_student_2021a_Ebox_B.Gain1_o
	  section.data(105).logicalSrcIdx = 114;
	  section.data(105).dtTransOffset = 128;
	
	  ;% robotarm_student_2021a_Ebox_B.Doubleclickswitch
	  section.data(106).logicalSrcIdx = 115;
	  section.data(106).dtTransOffset = 129;
	
	  ;% robotarm_student_2021a_Ebox_B.Object
	  section.data(107).logicalSrcIdx = 116;
	  section.data(107).dtTransOffset = 130;
	
	  ;% robotarm_student_2021a_Ebox_B.Plot
	  section.data(108).logicalSrcIdx = 117;
	  section.data(108).dtTransOffset = 131;
	
	  ;% robotarm_student_2021a_Ebox_B.Stop
	  section.data(109).logicalSrcIdx = 118;
	  section.data(109).dtTransOffset = 132;
	
	  ;% robotarm_student_2021a_Ebox_B.In1
	  section.data(110).logicalSrcIdx = 125;
	  section.data(110).dtTransOffset = 133;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% robotarm_student_2021a_Ebox_B.RelationalOperator
	  section.data(1).logicalSrcIdx = 126;
	  section.data(1).dtTransOffset = 0;
	
	  ;% robotarm_student_2021a_Ebox_B.Compare
	  section.data(2).logicalSrcIdx = 127;
	  section.data(2).dtTransOffset = 1;
	
	  ;% robotarm_student_2021a_Ebox_B.RelationalOperator_o
	  section.data(3).logicalSrcIdx = 128;
	  section.data(3).dtTransOffset = 2;
	
	  ;% robotarm_student_2021a_Ebox_B.RelationalOperator_n
	  section.data(4).logicalSrcIdx = 129;
	  section.data(4).dtTransOffset = 3;
	
	  ;% robotarm_student_2021a_Ebox_B.LogicalOperator1
	  section.data(5).logicalSrcIdx = 130;
	  section.data(5).dtTransOffset = 4;
	
	  ;% robotarm_student_2021a_Ebox_B.LogicalOperator1_d
	  section.data(6).logicalSrcIdx = 131;
	  section.data(6).dtTransOffset = 5;
	
	  ;% robotarm_student_2021a_Ebox_B.LogicalOperator1_o
	  section.data(7).logicalSrcIdx = 132;
	  section.data(7).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 13;
    sectIdxOffset = 4;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (robotarm_student_2021a_Ebox_DW)
    ;%
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	  ;% robotarm_student_2021a_Ebox_DW.DiscreteTimeIntegrator_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% robotarm_student_2021a_Ebox_DW.DiscreteTimeIntegrator_DSTATE_n
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% robotarm_student_2021a_Ebox_DW.UnitDelay_DSTATE
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% robotarm_student_2021a_Ebox_DW.DiscreteTimeIntegrator_DSTATE_p
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% robotarm_student_2021a_Ebox_DW.DiscreteTimeIntegrator_DSTAT_pn
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% robotarm_student_2021a_Ebox_DW.DiscreteTimeIntegrator_DSTATE_c
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% robotarm_student_2021a_Ebox_DW.DiscreteTimeIntegrator_DSTATE_i
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% robotarm_student_2021a_Ebox_DW.DiscreteTimeIntegrator_DSTATE_k
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% robotarm_student_2021a_Ebox_DW.UnitDelay1_DSTATE
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% robotarm_student_2021a_Ebox_DW.UD_DSTATE
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% robotarm_student_2021a_Ebox_DW.UD_DSTATE_n
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% robotarm_student_2021a_Ebox_DW.UD_DSTATE_e
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% robotarm_student_2021a_Ebox_DW.DelayInput1_DSTATE
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% robotarm_student_2021a_Ebox_DW.Discreteintegrator_DSTATE
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 24;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% robotarm_student_2021a_Ebox_DW.Delay_DSTATE
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 30;
      section.data(30)  = dumData; %prealloc
      
	  ;% robotarm_student_2021a_Ebox_DW.PrevY
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
	  ;% robotarm_student_2021a_Ebox_DW.PrevY_n
	  section.data(2).logicalSrcIdx = 16;
	  section.data(2).dtTransOffset = 1;
	
	  ;% robotarm_student_2021a_Ebox_DW.PrevY_h
	  section.data(3).logicalSrcIdx = 17;
	  section.data(3).dtTransOffset = 2;
	
	  ;% robotarm_student_2021a_Ebox_DW.PrevY_m
	  section.data(4).logicalSrcIdx = 18;
	  section.data(4).dtTransOffset = 3;
	
	  ;% robotarm_student_2021a_Ebox_DW.PrevY_c
	  section.data(5).logicalSrcIdx = 19;
	  section.data(5).dtTransOffset = 4;
	
	  ;% robotarm_student_2021a_Ebox_DW.PrevY_mz
	  section.data(6).logicalSrcIdx = 20;
	  section.data(6).dtTransOffset = 5;
	
	  ;% robotarm_student_2021a_Ebox_DW.currentcarPos
	  section.data(7).logicalSrcIdx = 21;
	  section.data(7).dtTransOffset = 6;
	
	  ;% robotarm_student_2021a_Ebox_DW.currentcarPos_f
	  section.data(8).logicalSrcIdx = 22;
	  section.data(8).dtTransOffset = 7;
	
	  ;% robotarm_student_2021a_Ebox_DW.currentcarPos_k
	  section.data(9).logicalSrcIdx = 23;
	  section.data(9).dtTransOffset = 8;
	
	  ;% robotarm_student_2021a_Ebox_DW.Dctintegrator_RWORK
	  section.data(10).logicalSrcIdx = 24;
	  section.data(10).dtTransOffset = 9;
	
	  ;% robotarm_student_2021a_Ebox_DW.Dctleadlag_RWORK
	  section.data(11).logicalSrcIdx = 25;
	  section.data(11).dtTransOffset = 11;
	
	  ;% robotarm_student_2021a_Ebox_DW.Dct1lowpass_RWORK
	  section.data(12).logicalSrcIdx = 26;
	  section.data(12).dtTransOffset = 13;
	
	  ;% robotarm_student_2021a_Ebox_DW.Dctleadlag_RWORK_b
	  section.data(13).logicalSrcIdx = 27;
	  section.data(13).dtTransOffset = 15;
	
	  ;% robotarm_student_2021a_Ebox_DW.Dct1lowpass_RWORK_g
	  section.data(14).logicalSrcIdx = 28;
	  section.data(14).dtTransOffset = 17;
	
	  ;% robotarm_student_2021a_Ebox_DW.Dctintegrator_RWORK_b
	  section.data(15).logicalSrcIdx = 29;
	  section.data(15).dtTransOffset = 19;
	
	  ;% robotarm_student_2021a_Ebox_DW.Dctleadlag_RWORK_a
	  section.data(16).logicalSrcIdx = 30;
	  section.data(16).dtTransOffset = 21;
	
	  ;% robotarm_student_2021a_Ebox_DW.Dct1lowpass_RWORK_m
	  section.data(17).logicalSrcIdx = 31;
	  section.data(17).dtTransOffset = 23;
	
	  ;% robotarm_student_2021a_Ebox_DW.Dctleadlag_RWORK_f
	  section.data(18).logicalSrcIdx = 32;
	  section.data(18).dtTransOffset = 25;
	
	  ;% robotarm_student_2021a_Ebox_DW.Dct1lowpass_RWORK_k
	  section.data(19).logicalSrcIdx = 33;
	  section.data(19).dtTransOffset = 27;
	
	  ;% robotarm_student_2021a_Ebox_DW.Dctintegrator_RWORK_m
	  section.data(20).logicalSrcIdx = 34;
	  section.data(20).dtTransOffset = 29;
	
	  ;% robotarm_student_2021a_Ebox_DW.Dctleadlag_RWORK_p
	  section.data(21).logicalSrcIdx = 35;
	  section.data(21).dtTransOffset = 31;
	
	  ;% robotarm_student_2021a_Ebox_DW.Dct1lowpass_RWORK_p
	  section.data(22).logicalSrcIdx = 36;
	  section.data(22).dtTransOffset = 33;
	
	  ;% robotarm_student_2021a_Ebox_DW.Dctleadlag_RWORK_o
	  section.data(23).logicalSrcIdx = 37;
	  section.data(23).dtTransOffset = 35;
	
	  ;% robotarm_student_2021a_Ebox_DW.Dct1lowpass_RWORK_gb
	  section.data(24).logicalSrcIdx = 38;
	  section.data(24).dtTransOffset = 37;
	
	  ;% robotarm_student_2021a_Ebox_DW.Dctintegrator3_RWORK
	  section.data(25).logicalSrcIdx = 39;
	  section.data(25).dtTransOffset = 39;
	
	  ;% robotarm_student_2021a_Ebox_DW.Dct1lowpass_RWORK_n
	  section.data(26).logicalSrcIdx = 40;
	  section.data(26).dtTransOffset = 41;
	
	  ;% robotarm_student_2021a_Ebox_DW.Dctleadlag_RWORK_l
	  section.data(27).logicalSrcIdx = 41;
	  section.data(27).dtTransOffset = 43;
	
	  ;% robotarm_student_2021a_Ebox_DW.Dctintegrator3_RWORK_g
	  section.data(28).logicalSrcIdx = 42;
	  section.data(28).dtTransOffset = 45;
	
	  ;% robotarm_student_2021a_Ebox_DW.Dct1lowpass_RWORK_c
	  section.data(29).logicalSrcIdx = 43;
	  section.data(29).dtTransOffset = 47;
	
	  ;% robotarm_student_2021a_Ebox_DW.Dctleadlag_RWORK_g
	  section.data(30).logicalSrcIdx = 44;
	  section.data(30).dtTransOffset = 49;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% robotarm_student_2021a_Ebox_DW.sfEvent
	  section.data(1).logicalSrcIdx = 45;
	  section.data(1).dtTransOffset = 0;
	
	  ;% robotarm_student_2021a_Ebox_DW.sfEvent_j
	  section.data(2).logicalSrcIdx = 46;
	  section.data(2).dtTransOffset = 1;
	
	  ;% robotarm_student_2021a_Ebox_DW.sfEvent_jk
	  section.data(3).logicalSrcIdx = 47;
	  section.data(3).dtTransOffset = 2;
	
	  ;% robotarm_student_2021a_Ebox_DW.sfEvent_f
	  section.data(4).logicalSrcIdx = 48;
	  section.data(4).dtTransOffset = 3;
	
	  ;% robotarm_student_2021a_Ebox_DW.sfEvent_b
	  section.data(5).logicalSrcIdx = 49;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% robotarm_student_2021a_Ebox_DW.is_c4_robotarm_student_2021a_Eb
	  section.data(1).logicalSrcIdx = 50;
	  section.data(1).dtTransOffset = 0;
	
	  ;% robotarm_student_2021a_Ebox_DW.is_c7_robotarm_student_2021a_Eb
	  section.data(2).logicalSrcIdx = 51;
	  section.data(2).dtTransOffset = 1;
	
	  ;% robotarm_student_2021a_Ebox_DW.is_c6_robotarm_student_2021a_Eb
	  section.data(3).logicalSrcIdx = 52;
	  section.data(3).dtTransOffset = 2;
	
	  ;% robotarm_student_2021a_Ebox_DW.is_c5_robotarm_student_2021a_Eb
	  section.data(4).logicalSrcIdx = 53;
	  section.data(4).dtTransOffset = 3;
	
	  ;% robotarm_student_2021a_Ebox_DW.is_Object_Detection
	  section.data(5).logicalSrcIdx = 54;
	  section.data(5).dtTransOffset = 4;
	
	  ;% robotarm_student_2021a_Ebox_DW.is_Belt
	  section.data(6).logicalSrcIdx = 55;
	  section.data(6).dtTransOffset = 5;
	
	  ;% robotarm_student_2021a_Ebox_DW.is_Robot_Arm
	  section.data(7).logicalSrcIdx = 56;
	  section.data(7).dtTransOffset = 6;
	
	  ;% robotarm_student_2021a_Ebox_DW.is_Vacuum
	  section.data(8).logicalSrcIdx = 57;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% robotarm_student_2021a_Ebox_DW.temporalCounter_i1
	  section.data(1).logicalSrcIdx = 58;
	  section.data(1).dtTransOffset = 0;
	
	  ;% robotarm_student_2021a_Ebox_DW.temporalCounter_i1_k
	  section.data(2).logicalSrcIdx = 59;
	  section.data(2).dtTransOffset = 1;
	
	  ;% robotarm_student_2021a_Ebox_DW.temporalCounter_i1_a
	  section.data(3).logicalSrcIdx = 60;
	  section.data(3).dtTransOffset = 2;
	
	  ;% robotarm_student_2021a_Ebox_DW.temporalCounter_i1_p
	  section.data(4).logicalSrcIdx = 61;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% robotarm_student_2021a_Ebox_DW.Subsystem3_SubsysRanBC
	  section.data(1).logicalSrcIdx = 62;
	  section.data(1).dtTransOffset = 0;
	
	  ;% robotarm_student_2021a_Ebox_DW.IfActionSubsystem1_SubsysRanBC
	  section.data(2).logicalSrcIdx = 63;
	  section.data(2).dtTransOffset = 1;
	
	  ;% robotarm_student_2021a_Ebox_DW.IfActionSubsystem_SubsysRanBC
	  section.data(3).logicalSrcIdx = 64;
	  section.data(3).dtTransOffset = 2;
	
	  ;% robotarm_student_2021a_Ebox_DW.Controller_SubsysRanBC
	  section.data(4).logicalSrcIdx = 65;
	  section.data(4).dtTransOffset = 3;
	
	  ;% robotarm_student_2021a_Ebox_DW.EnabledSubsystem_SubsysRanBC
	  section.data(5).logicalSrcIdx = 66;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% robotarm_student_2021a_Ebox_DW.is_active_c4_robotarm_student_2
	  section.data(1).logicalSrcIdx = 67;
	  section.data(1).dtTransOffset = 0;
	
	  ;% robotarm_student_2021a_Ebox_DW.is_active_c7_robotarm_student_2
	  section.data(2).logicalSrcIdx = 68;
	  section.data(2).dtTransOffset = 1;
	
	  ;% robotarm_student_2021a_Ebox_DW.is_active_c6_robotarm_student_2
	  section.data(3).logicalSrcIdx = 69;
	  section.data(3).dtTransOffset = 2;
	
	  ;% robotarm_student_2021a_Ebox_DW.is_active_c5_robotarm_student_2
	  section.data(4).logicalSrcIdx = 70;
	  section.data(4).dtTransOffset = 3;
	
	  ;% robotarm_student_2021a_Ebox_DW.is_active_c3_robotarm_student_2
	  section.data(5).logicalSrcIdx = 71;
	  section.data(5).dtTransOffset = 4;
	
	  ;% robotarm_student_2021a_Ebox_DW.is_active_Object_Detection
	  section.data(6).logicalSrcIdx = 72;
	  section.data(6).dtTransOffset = 5;
	
	  ;% robotarm_student_2021a_Ebox_DW.is_active_Belt
	  section.data(7).logicalSrcIdx = 73;
	  section.data(7).dtTransOffset = 6;
	
	  ;% robotarm_student_2021a_Ebox_DW.is_active_Robot_Arm
	  section.data(8).logicalSrcIdx = 74;
	  section.data(8).dtTransOffset = 7;
	
	  ;% robotarm_student_2021a_Ebox_DW.is_active_Vacuum
	  section.data(9).logicalSrcIdx = 75;
	  section.data(9).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% robotarm_student_2021a_Ebox_DW.doneDoubleBufferReInit
	  section.data(1).logicalSrcIdx = 76;
	  section.data(1).dtTransOffset = 0;
	
	  ;% robotarm_student_2021a_Ebox_DW.Controller_MODE
	  section.data(2).logicalSrcIdx = 77;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% robotarm_student_2021a_Ebox_DW.SerialWrite.obj
	  section.data(1).logicalSrcIdx = 78;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% robotarm_student_2021a_Ebox_DW.SerialWrite.objisempty
	  section.data(1).logicalSrcIdx = 79;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% robotarm_student_2021a_Ebox_DW.SerialWrite1.obj
	  section.data(1).logicalSrcIdx = 80;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% robotarm_student_2021a_Ebox_DW.SerialWrite1.objisempty
	  section.data(1).logicalSrcIdx = 81;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2147366462;
  targMap.checksum1 = 15235078;
  targMap.checksum2 = 1026052689;
  targMap.checksum3 = 1568913584;

