  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
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
    ;% Auto data (Callibration_check_Robot_Ipos_P)
    ;%
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_P.DiscreteDerivative_ICPrevScaled
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Callibration_check_Robot_Ipos_P.DiscreteDerivative_ICPrevScal_b
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Callibration_check_Robot_Ipos_P.DiscreteDerivative_ICPrevScal_n
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Callibration_check_Robot_Ipos_P.DiscreteDerivative_ICPrevSca_bn
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Callibration_check_Robot_Ipos_P.DiscreteDerivative_ICPrevScal_o
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Callibration_check_Robot_Ipos_P.DiscreteDerivative_ICPrevScal_c
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Callibration_check_Robot_Ipos_P.CompareToConstant_const
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Callibration_check_Robot_Ipos_P.DetectChange_vinit
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_P.MeasurementBlock_N_samples
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_P.CompareToConstant1_const
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Callibration_check_Robot_Ipos_P.MeasurementBlock_trigger_comman
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Callibration_check_Robot_Ipos_P.MeasurementBlock_triggertype
	  section.data(3).logicalSrcIdx = 11;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 234;
      section.data(234)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_P.Delays_Y0
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Callibration_check_Robot_Ipos_P.Suck_Value
	  section.data(2).logicalSrcIdx = 13;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Callibration_check_Robot_Ipos_P.Blow_Value
	  section.data(3).logicalSrcIdx = 14;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Callibration_check_Robot_Ipos_P.RobotV_Y0
	  section.data(4).logicalSrcIdx = 15;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Callibration_check_Robot_Ipos_P.ConveyorV_Y0
	  section.data(5).logicalSrcIdx = 16;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Callibration_check_Robot_Ipos_P.VacuumV_Y0
	  section.data(6).logicalSrcIdx = 17;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Callibration_check_Robot_Ipos_P.Blowsuck_Y0
	  section.data(7).logicalSrcIdx = 18;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Callibration_check_Robot_Ipos_P.Objectdetectionmatrix_Value
	  section.data(8).logicalSrcIdx = 19;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Callibration_check_Robot_Ipos_P.Discreteintegrator_gainval
	  section.data(9).logicalSrcIdx = 20;
	  section.data(9).dtTransOffset = 19;
	
	  ;% Callibration_check_Robot_Ipos_P.Discreteintegrator_IC
	  section.data(10).logicalSrcIdx = 21;
	  section.data(10).dtTransOffset = 20;
	
	  ;% Callibration_check_Robot_Ipos_P.Gain1_Gain
	  section.data(11).logicalSrcIdx = 22;
	  section.data(11).dtTransOffset = 21;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctintegrator3_P1_Size
	  section.data(12).logicalSrcIdx = 23;
	  section.data(12).dtTransOffset = 22;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctintegrator3_P1
	  section.data(13).logicalSrcIdx = 24;
	  section.data(13).dtTransOffset = 24;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctintegrator3_P2_Size
	  section.data(14).logicalSrcIdx = 25;
	  section.data(14).dtTransOffset = 25;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctintegrator3_P2
	  section.data(15).logicalSrcIdx = 26;
	  section.data(15).dtTransOffset = 27;
	
	  ;% Callibration_check_Robot_Ipos_P.Dct1lowpass_P1_Size
	  section.data(16).logicalSrcIdx = 27;
	  section.data(16).dtTransOffset = 28;
	
	  ;% Callibration_check_Robot_Ipos_P.Dct1lowpass_P1
	  section.data(17).logicalSrcIdx = 28;
	  section.data(17).dtTransOffset = 30;
	
	  ;% Callibration_check_Robot_Ipos_P.Dct1lowpass_P2_Size
	  section.data(18).logicalSrcIdx = 29;
	  section.data(18).dtTransOffset = 31;
	
	  ;% Callibration_check_Robot_Ipos_P.Dct1lowpass_P2
	  section.data(19).logicalSrcIdx = 30;
	  section.data(19).dtTransOffset = 33;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P1_Size
	  section.data(20).logicalSrcIdx = 31;
	  section.data(20).dtTransOffset = 34;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P1
	  section.data(21).logicalSrcIdx = 32;
	  section.data(21).dtTransOffset = 36;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P2_Size
	  section.data(22).logicalSrcIdx = 33;
	  section.data(22).dtTransOffset = 37;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P2
	  section.data(23).logicalSrcIdx = 34;
	  section.data(23).dtTransOffset = 39;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P3_Size
	  section.data(24).logicalSrcIdx = 35;
	  section.data(24).dtTransOffset = 40;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P3
	  section.data(25).logicalSrcIdx = 36;
	  section.data(25).dtTransOffset = 42;
	
	  ;% Callibration_check_Robot_Ipos_P.ReferenceRrad_Value
	  section.data(26).logicalSrcIdx = 37;
	  section.data(26).dtTransOffset = 43;
	
	  ;% Callibration_check_Robot_Ipos_P.Gain_Gain
	  section.data(27).logicalSrcIdx = 38;
	  section.data(27).dtTransOffset = 44;
	
	  ;% Callibration_check_Robot_Ipos_P.FeedfowardRV_Value
	  section.data(28).logicalSrcIdx = 39;
	  section.data(28).dtTransOffset = 45;
	
	  ;% Callibration_check_Robot_Ipos_P.ReferenceXrad_Value
	  section.data(29).logicalSrcIdx = 40;
	  section.data(29).dtTransOffset = 46;
	
	  ;% Callibration_check_Robot_Ipos_P.Gain1_Gain_c
	  section.data(30).logicalSrcIdx = 41;
	  section.data(30).dtTransOffset = 47;
	
	  ;% Callibration_check_Robot_Ipos_P.FeedfowardXV_Value
	  section.data(31).logicalSrcIdx = 42;
	  section.data(31).dtTransOffset = 48;
	
	  ;% Callibration_check_Robot_Ipos_P.ReferenceZrad_Value
	  section.data(32).logicalSrcIdx = 43;
	  section.data(32).dtTransOffset = 49;
	
	  ;% Callibration_check_Robot_Ipos_P.Gain_Gain_b
	  section.data(33).logicalSrcIdx = 44;
	  section.data(33).dtTransOffset = 50;
	
	  ;% Callibration_check_Robot_Ipos_P.FeedfowardZV_Value
	  section.data(34).logicalSrcIdx = 45;
	  section.data(34).dtTransOffset = 51;
	
	  ;% Callibration_check_Robot_Ipos_P.Conveyorspeedmms_Value
	  section.data(35).logicalSrcIdx = 46;
	  section.data(35).dtTransOffset = 52;
	
	  ;% Callibration_check_Robot_Ipos_P.Saturation_UpperSat
	  section.data(36).logicalSrcIdx = 47;
	  section.data(36).dtTransOffset = 53;
	
	  ;% Callibration_check_Robot_Ipos_P.Saturation_LowerSat
	  section.data(37).logicalSrcIdx = 48;
	  section.data(37).dtTransOffset = 54;
	
	  ;% Callibration_check_Robot_Ipos_P.ReferenceVacuumbar_Value
	  section.data(38).logicalSrcIdx = 49;
	  section.data(38).dtTransOffset = 55;
	
	  ;% Callibration_check_Robot_Ipos_P.Gain1_Gain_j
	  section.data(39).logicalSrcIdx = 50;
	  section.data(39).dtTransOffset = 56;
	
	  ;% Callibration_check_Robot_Ipos_P.Object_Value
	  section.data(40).logicalSrcIdx = 51;
	  section.data(40).dtTransOffset = 57;
	
	  ;% Callibration_check_Robot_Ipos_P.Plot_Value
	  section.data(41).logicalSrcIdx = 52;
	  section.data(41).dtTransOffset = 58;
	
	  ;% Callibration_check_Robot_Ipos_P.Stop_Value
	  section.data(42).logicalSrcIdx = 53;
	  section.data(42).dtTransOffset = 59;
	
	  ;% Callibration_check_Robot_Ipos_P.HomingRunningSwitch2_Threshold
	  section.data(43).logicalSrcIdx = 54;
	  section.data(43).dtTransOffset = 60;
	
	  ;% Callibration_check_Robot_Ipos_P.HomingRunningSwitch1_Threshold
	  section.data(44).logicalSrcIdx = 55;
	  section.data(44).dtTransOffset = 61;
	
	  ;% Callibration_check_Robot_Ipos_P.Constant2_Value
	  section.data(45).logicalSrcIdx = 56;
	  section.data(45).dtTransOffset = 62;
	
	  ;% Callibration_check_Robot_Ipos_P.HomingRunningSwitch_Threshold
	  section.data(46).logicalSrcIdx = 57;
	  section.data(46).dtTransOffset = 63;
	
	  ;% Callibration_check_Robot_Ipos_P.Constant1_Value
	  section.data(47).logicalSrcIdx = 58;
	  section.data(47).dtTransOffset = 64;
	
	  ;% Callibration_check_Robot_Ipos_P.HomingRunningSwitch_Threshold_k
	  section.data(48).logicalSrcIdx = 59;
	  section.data(48).dtTransOffset = 65;
	
	  ;% Callibration_check_Robot_Ipos_P.Constant1_Value_j
	  section.data(49).logicalSrcIdx = 60;
	  section.data(49).dtTransOffset = 66;
	
	  ;% Callibration_check_Robot_Ipos_P.SFunction_P1_Size
	  section.data(50).logicalSrcIdx = 61;
	  section.data(50).dtTransOffset = 67;
	
	  ;% Callibration_check_Robot_Ipos_P.SFunction_P1
	  section.data(51).logicalSrcIdx = 62;
	  section.data(51).dtTransOffset = 69;
	
	  ;% Callibration_check_Robot_Ipos_P.SFunction_P2_Size
	  section.data(52).logicalSrcIdx = 63;
	  section.data(52).dtTransOffset = 70;
	
	  ;% Callibration_check_Robot_Ipos_P.SFunction_P2
	  section.data(53).logicalSrcIdx = 64;
	  section.data(53).dtTransOffset = 72;
	
	  ;% Callibration_check_Robot_Ipos_P.ec_Ipos_P1_Size
	  section.data(54).logicalSrcIdx = 65;
	  section.data(54).dtTransOffset = 73;
	
	  ;% Callibration_check_Robot_Ipos_P.ec_Ipos_P1
	  section.data(55).logicalSrcIdx = 66;
	  section.data(55).dtTransOffset = 75;
	
	  ;% Callibration_check_Robot_Ipos_P.Gain_Gain_c
	  section.data(56).logicalSrcIdx = 67;
	  section.data(56).dtTransOffset = 76;
	
	  ;% Callibration_check_Robot_Ipos_P.set_robot_calibration_r_Value
	  section.data(57).logicalSrcIdx = 68;
	  section.data(57).dtTransOffset = 77;
	
	  ;% Callibration_check_Robot_Ipos_P.Constant1_Value_f
	  section.data(58).logicalSrcIdx = 69;
	  section.data(58).dtTransOffset = 78;
	
	  ;% Callibration_check_Robot_Ipos_P.DiscreteTimeIntegrator_gainval
	  section.data(59).logicalSrcIdx = 70;
	  section.data(59).dtTransOffset = 79;
	
	  ;% Callibration_check_Robot_Ipos_P.HomingRunningSwitch1_Threshol_c
	  section.data(60).logicalSrcIdx = 71;
	  section.data(60).dtTransOffset = 80;
	
	  ;% Callibration_check_Robot_Ipos_P.Constant3_Value
	  section.data(61).logicalSrcIdx = 72;
	  section.data(61).dtTransOffset = 81;
	
	  ;% Callibration_check_Robot_Ipos_P.Constant4_Value
	  section.data(62).logicalSrcIdx = 73;
	  section.data(62).dtTransOffset = 82;
	
	  ;% Callibration_check_Robot_Ipos_P.DiscreteTimeIntegrator_gainva_p
	  section.data(63).logicalSrcIdx = 74;
	  section.data(63).dtTransOffset = 83;
	
	  ;% Callibration_check_Robot_Ipos_P.DiscreteTimeIntegrator_IC
	  section.data(64).logicalSrcIdx = 75;
	  section.data(64).dtTransOffset = 84;
	
	  ;% Callibration_check_Robot_Ipos_P.Constant_Value
	  section.data(65).logicalSrcIdx = 76;
	  section.data(65).dtTransOffset = 85;
	
	  ;% Callibration_check_Robot_Ipos_P.Gain1_Gain_g
	  section.data(66).logicalSrcIdx = 77;
	  section.data(66).dtTransOffset = 86;
	
	  ;% Callibration_check_Robot_Ipos_P.DiscreteTimeIntegrator_gainva_o
	  section.data(67).logicalSrcIdx = 78;
	  section.data(67).dtTransOffset = 87;
	
	  ;% Callibration_check_Robot_Ipos_P.DiscreteTimeIntegrator_IC_k
	  section.data(68).logicalSrcIdx = 79;
	  section.data(68).dtTransOffset = 88;
	
	  ;% Callibration_check_Robot_Ipos_P.set_robot_calibration_x_Value
	  section.data(69).logicalSrcIdx = 80;
	  section.data(69).dtTransOffset = 89;
	
	  ;% Callibration_check_Robot_Ipos_P.Constant1_Value_c
	  section.data(70).logicalSrcIdx = 81;
	  section.data(70).dtTransOffset = 90;
	
	  ;% Callibration_check_Robot_Ipos_P.DiscreteTimeIntegrator_gainva_m
	  section.data(71).logicalSrcIdx = 82;
	  section.data(71).dtTransOffset = 91;
	
	  ;% Callibration_check_Robot_Ipos_P.HomingRunningSwitch1_Threshol_b
	  section.data(72).logicalSrcIdx = 83;
	  section.data(72).dtTransOffset = 92;
	
	  ;% Callibration_check_Robot_Ipos_P.Constant2_Value_h
	  section.data(73).logicalSrcIdx = 84;
	  section.data(73).dtTransOffset = 93;
	
	  ;% Callibration_check_Robot_Ipos_P.Constant3_Value_g
	  section.data(74).logicalSrcIdx = 85;
	  section.data(74).dtTransOffset = 94;
	
	  ;% Callibration_check_Robot_Ipos_P.Constant_Value_i
	  section.data(75).logicalSrcIdx = 86;
	  section.data(75).dtTransOffset = 95;
	
	  ;% Callibration_check_Robot_Ipos_P.Gain2_Gain
	  section.data(76).logicalSrcIdx = 87;
	  section.data(76).dtTransOffset = 96;
	
	  ;% Callibration_check_Robot_Ipos_P.DiscreteTimeIntegrator_gainva_i
	  section.data(77).logicalSrcIdx = 88;
	  section.data(77).dtTransOffset = 97;
	
	  ;% Callibration_check_Robot_Ipos_P.DiscreteTimeIntegrator_IC_g
	  section.data(78).logicalSrcIdx = 89;
	  section.data(78).dtTransOffset = 98;
	
	  ;% Callibration_check_Robot_Ipos_P.set_robot_calibration_z_Value
	  section.data(79).logicalSrcIdx = 90;
	  section.data(79).dtTransOffset = 99;
	
	  ;% Callibration_check_Robot_Ipos_P.Constant1_Value_i
	  section.data(80).logicalSrcIdx = 91;
	  section.data(80).dtTransOffset = 100;
	
	  ;% Callibration_check_Robot_Ipos_P.DiscreteTimeIntegrator_gainva_a
	  section.data(81).logicalSrcIdx = 92;
	  section.data(81).dtTransOffset = 101;
	
	  ;% Callibration_check_Robot_Ipos_P.HomingRunningSwitch1_Threshol_o
	  section.data(82).logicalSrcIdx = 93;
	  section.data(82).dtTransOffset = 102;
	
	  ;% Callibration_check_Robot_Ipos_P.Constant5_Value
	  section.data(83).logicalSrcIdx = 94;
	  section.data(83).dtTransOffset = 103;
	
	  ;% Callibration_check_Robot_Ipos_P.Constant6_Value
	  section.data(84).logicalSrcIdx = 95;
	  section.data(84).dtTransOffset = 104;
	
	  ;% Callibration_check_Robot_Ipos_P.Constant_Value_e
	  section.data(85).logicalSrcIdx = 96;
	  section.data(85).dtTransOffset = 105;
	
	  ;% Callibration_check_Robot_Ipos_P.UnitDelay_InitialCondition
	  section.data(86).logicalSrcIdx = 97;
	  section.data(86).dtTransOffset = 106;
	
	  ;% Callibration_check_Robot_Ipos_P.Gain_Gain_l
	  section.data(87).logicalSrcIdx = 98;
	  section.data(87).dtTransOffset = 107;
	
	  ;% Callibration_check_Robot_Ipos_P.Constant_Value_n
	  section.data(88).logicalSrcIdx = 99;
	  section.data(88).dtTransOffset = 108;
	
	  ;% Callibration_check_Robot_Ipos_P.Gain3_Gain
	  section.data(89).logicalSrcIdx = 100;
	  section.data(89).dtTransOffset = 109;
	
	  ;% Callibration_check_Robot_Ipos_P.UnitDelay1_InitialCondition
	  section.data(90).logicalSrcIdx = 101;
	  section.data(90).dtTransOffset = 110;
	
	  ;% Callibration_check_Robot_Ipos_P.HomingRunningSwitch_Threshold_g
	  section.data(91).logicalSrcIdx = 102;
	  section.data(91).dtTransOffset = 111;
	
	  ;% Callibration_check_Robot_Ipos_P.ResetEncoderR_P1_Size
	  section.data(92).logicalSrcIdx = 103;
	  section.data(92).dtTransOffset = 112;
	
	  ;% Callibration_check_Robot_Ipos_P.ResetEncoderR_P1
	  section.data(93).logicalSrcIdx = 104;
	  section.data(93).dtTransOffset = 114;
	
	  ;% Callibration_check_Robot_Ipos_P.Gain_Gain_d
	  section.data(94).logicalSrcIdx = 105;
	  section.data(94).dtTransOffset = 115;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctintegrator_P1_Size
	  section.data(95).logicalSrcIdx = 106;
	  section.data(95).dtTransOffset = 116;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctintegrator_P1
	  section.data(96).logicalSrcIdx = 107;
	  section.data(96).dtTransOffset = 118;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctintegrator_P2_Size
	  section.data(97).logicalSrcIdx = 108;
	  section.data(97).dtTransOffset = 119;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctintegrator_P2
	  section.data(98).logicalSrcIdx = 109;
	  section.data(98).dtTransOffset = 121;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P1_Size_h
	  section.data(99).logicalSrcIdx = 110;
	  section.data(99).dtTransOffset = 122;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P1_m
	  section.data(100).logicalSrcIdx = 111;
	  section.data(100).dtTransOffset = 124;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P2_Size_j
	  section.data(101).logicalSrcIdx = 112;
	  section.data(101).dtTransOffset = 125;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P2_o
	  section.data(102).logicalSrcIdx = 113;
	  section.data(102).dtTransOffset = 127;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P3_Size_k
	  section.data(103).logicalSrcIdx = 114;
	  section.data(103).dtTransOffset = 128;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P3_c
	  section.data(104).logicalSrcIdx = 115;
	  section.data(104).dtTransOffset = 130;
	
	  ;% Callibration_check_Robot_Ipos_P.Dct1lowpass_P1_Size_b
	  section.data(105).logicalSrcIdx = 116;
	  section.data(105).dtTransOffset = 131;
	
	  ;% Callibration_check_Robot_Ipos_P.Dct1lowpass_P1_e
	  section.data(106).logicalSrcIdx = 117;
	  section.data(106).dtTransOffset = 133;
	
	  ;% Callibration_check_Robot_Ipos_P.Dct1lowpass_P2_Size_c
	  section.data(107).logicalSrcIdx = 118;
	  section.data(107).dtTransOffset = 134;
	
	  ;% Callibration_check_Robot_Ipos_P.Dct1lowpass_P2_c
	  section.data(108).logicalSrcIdx = 119;
	  section.data(108).dtTransOffset = 136;
	
	  ;% Callibration_check_Robot_Ipos_P.HomingRunningSwitch_Threshold_o
	  section.data(109).logicalSrcIdx = 120;
	  section.data(109).dtTransOffset = 137;
	
	  ;% Callibration_check_Robot_Ipos_P.Gain_Gain_br
	  section.data(110).logicalSrcIdx = 121;
	  section.data(110).dtTransOffset = 138;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P1_Size_c
	  section.data(111).logicalSrcIdx = 122;
	  section.data(111).dtTransOffset = 139;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P1_b
	  section.data(112).logicalSrcIdx = 123;
	  section.data(112).dtTransOffset = 141;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P2_Size_i
	  section.data(113).logicalSrcIdx = 124;
	  section.data(113).dtTransOffset = 142;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P2_m
	  section.data(114).logicalSrcIdx = 125;
	  section.data(114).dtTransOffset = 144;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P3_Size_n
	  section.data(115).logicalSrcIdx = 126;
	  section.data(115).dtTransOffset = 145;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P3_l
	  section.data(116).logicalSrcIdx = 127;
	  section.data(116).dtTransOffset = 147;
	
	  ;% Callibration_check_Robot_Ipos_P.Dct1lowpass_P1_Size_p
	  section.data(117).logicalSrcIdx = 128;
	  section.data(117).dtTransOffset = 148;
	
	  ;% Callibration_check_Robot_Ipos_P.Dct1lowpass_P1_n
	  section.data(118).logicalSrcIdx = 129;
	  section.data(118).dtTransOffset = 150;
	
	  ;% Callibration_check_Robot_Ipos_P.Dct1lowpass_P2_Size_h
	  section.data(119).logicalSrcIdx = 130;
	  section.data(119).dtTransOffset = 151;
	
	  ;% Callibration_check_Robot_Ipos_P.Dct1lowpass_P2_a
	  section.data(120).logicalSrcIdx = 131;
	  section.data(120).dtTransOffset = 153;
	
	  ;% Callibration_check_Robot_Ipos_P.Gain1_Gain_n
	  section.data(121).logicalSrcIdx = 132;
	  section.data(121).dtTransOffset = 154;
	
	  ;% Callibration_check_Robot_Ipos_P.ResetEncoderR1_P1_Size
	  section.data(122).logicalSrcIdx = 133;
	  section.data(122).dtTransOffset = 155;
	
	  ;% Callibration_check_Robot_Ipos_P.ResetEncoderR1_P1
	  section.data(123).logicalSrcIdx = 134;
	  section.data(123).dtTransOffset = 157;
	
	  ;% Callibration_check_Robot_Ipos_P.Gain1_Gain_d
	  section.data(124).logicalSrcIdx = 135;
	  section.data(124).dtTransOffset = 158;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctintegrator_P1_Size_a
	  section.data(125).logicalSrcIdx = 136;
	  section.data(125).dtTransOffset = 159;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctintegrator_P1_j
	  section.data(126).logicalSrcIdx = 137;
	  section.data(126).dtTransOffset = 161;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctintegrator_P2_Size_p
	  section.data(127).logicalSrcIdx = 138;
	  section.data(127).dtTransOffset = 162;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctintegrator_P2_e
	  section.data(128).logicalSrcIdx = 139;
	  section.data(128).dtTransOffset = 164;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P1_Size_o
	  section.data(129).logicalSrcIdx = 140;
	  section.data(129).dtTransOffset = 165;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P1_a
	  section.data(130).logicalSrcIdx = 141;
	  section.data(130).dtTransOffset = 167;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P2_Size_p
	  section.data(131).logicalSrcIdx = 142;
	  section.data(131).dtTransOffset = 168;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P2_g
	  section.data(132).logicalSrcIdx = 143;
	  section.data(132).dtTransOffset = 170;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P3_Size_e
	  section.data(133).logicalSrcIdx = 144;
	  section.data(133).dtTransOffset = 171;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P3_f
	  section.data(134).logicalSrcIdx = 145;
	  section.data(134).dtTransOffset = 173;
	
	  ;% Callibration_check_Robot_Ipos_P.Dct1lowpass_P1_Size_g
	  section.data(135).logicalSrcIdx = 146;
	  section.data(135).dtTransOffset = 174;
	
	  ;% Callibration_check_Robot_Ipos_P.Dct1lowpass_P1_p
	  section.data(136).logicalSrcIdx = 147;
	  section.data(136).dtTransOffset = 176;
	
	  ;% Callibration_check_Robot_Ipos_P.Dct1lowpass_P2_Size_hw
	  section.data(137).logicalSrcIdx = 148;
	  section.data(137).dtTransOffset = 177;
	
	  ;% Callibration_check_Robot_Ipos_P.Dct1lowpass_P2_e
	  section.data(138).logicalSrcIdx = 149;
	  section.data(138).dtTransOffset = 179;
	
	  ;% Callibration_check_Robot_Ipos_P.Gain1_Gain_f
	  section.data(139).logicalSrcIdx = 150;
	  section.data(139).dtTransOffset = 180;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P1_Size_j
	  section.data(140).logicalSrcIdx = 151;
	  section.data(140).dtTransOffset = 181;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P1_d
	  section.data(141).logicalSrcIdx = 152;
	  section.data(141).dtTransOffset = 183;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P2_Size_g
	  section.data(142).logicalSrcIdx = 153;
	  section.data(142).dtTransOffset = 184;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P2_n
	  section.data(143).logicalSrcIdx = 154;
	  section.data(143).dtTransOffset = 186;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P3_Size_j
	  section.data(144).logicalSrcIdx = 155;
	  section.data(144).dtTransOffset = 187;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P3_k
	  section.data(145).logicalSrcIdx = 156;
	  section.data(145).dtTransOffset = 189;
	
	  ;% Callibration_check_Robot_Ipos_P.Dct1lowpass_P1_Size_pc
	  section.data(146).logicalSrcIdx = 157;
	  section.data(146).dtTransOffset = 190;
	
	  ;% Callibration_check_Robot_Ipos_P.Dct1lowpass_P1_o
	  section.data(147).logicalSrcIdx = 158;
	  section.data(147).dtTransOffset = 192;
	
	  ;% Callibration_check_Robot_Ipos_P.Dct1lowpass_P2_Size_f
	  section.data(148).logicalSrcIdx = 159;
	  section.data(148).dtTransOffset = 193;
	
	  ;% Callibration_check_Robot_Ipos_P.Dct1lowpass_P2_l
	  section.data(149).logicalSrcIdx = 160;
	  section.data(149).dtTransOffset = 195;
	
	  ;% Callibration_check_Robot_Ipos_P.Gain_Gain_p
	  section.data(150).logicalSrcIdx = 161;
	  section.data(150).dtTransOffset = 196;
	
	  ;% Callibration_check_Robot_Ipos_P.Saturation1_UpperSat
	  section.data(151).logicalSrcIdx = 162;
	  section.data(151).dtTransOffset = 197;
	
	  ;% Callibration_check_Robot_Ipos_P.Saturation1_LowerSat
	  section.data(152).logicalSrcIdx = 163;
	  section.data(152).dtTransOffset = 198;
	
	  ;% Callibration_check_Robot_Ipos_P.ResetEncoderR1_P1_Size_p
	  section.data(153).logicalSrcIdx = 164;
	  section.data(153).dtTransOffset = 199;
	
	  ;% Callibration_check_Robot_Ipos_P.ResetEncoderR1_P1_h
	  section.data(154).logicalSrcIdx = 165;
	  section.data(154).dtTransOffset = 201;
	
	  ;% Callibration_check_Robot_Ipos_P.Gain_Gain_e
	  section.data(155).logicalSrcIdx = 166;
	  section.data(155).dtTransOffset = 202;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctintegrator_P1_Size_d
	  section.data(156).logicalSrcIdx = 167;
	  section.data(156).dtTransOffset = 203;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctintegrator_P1_d
	  section.data(157).logicalSrcIdx = 168;
	  section.data(157).dtTransOffset = 205;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctintegrator_P2_Size_b
	  section.data(158).logicalSrcIdx = 169;
	  section.data(158).dtTransOffset = 206;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctintegrator_P2_g
	  section.data(159).logicalSrcIdx = 170;
	  section.data(159).dtTransOffset = 208;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P1_Size_b
	  section.data(160).logicalSrcIdx = 171;
	  section.data(160).dtTransOffset = 209;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P1_c
	  section.data(161).logicalSrcIdx = 172;
	  section.data(161).dtTransOffset = 211;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P2_Size_pu
	  section.data(162).logicalSrcIdx = 173;
	  section.data(162).dtTransOffset = 212;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P2_c
	  section.data(163).logicalSrcIdx = 174;
	  section.data(163).dtTransOffset = 214;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P3_Size_ja
	  section.data(164).logicalSrcIdx = 175;
	  section.data(164).dtTransOffset = 215;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P3_o
	  section.data(165).logicalSrcIdx = 176;
	  section.data(165).dtTransOffset = 217;
	
	  ;% Callibration_check_Robot_Ipos_P.Dct1lowpass_P1_Size_n
	  section.data(166).logicalSrcIdx = 177;
	  section.data(166).dtTransOffset = 218;
	
	  ;% Callibration_check_Robot_Ipos_P.Dct1lowpass_P1_f
	  section.data(167).logicalSrcIdx = 178;
	  section.data(167).dtTransOffset = 220;
	
	  ;% Callibration_check_Robot_Ipos_P.Dct1lowpass_P2_Size_e
	  section.data(168).logicalSrcIdx = 179;
	  section.data(168).dtTransOffset = 221;
	
	  ;% Callibration_check_Robot_Ipos_P.Dct1lowpass_P2_ee
	  section.data(169).logicalSrcIdx = 180;
	  section.data(169).dtTransOffset = 223;
	
	  ;% Callibration_check_Robot_Ipos_P.Gain_Gain_dk
	  section.data(170).logicalSrcIdx = 181;
	  section.data(170).dtTransOffset = 224;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P1_Size_p
	  section.data(171).logicalSrcIdx = 182;
	  section.data(171).dtTransOffset = 225;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P1_l
	  section.data(172).logicalSrcIdx = 183;
	  section.data(172).dtTransOffset = 227;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P2_Size_e
	  section.data(173).logicalSrcIdx = 184;
	  section.data(173).dtTransOffset = 228;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P2_l
	  section.data(174).logicalSrcIdx = 185;
	  section.data(174).dtTransOffset = 230;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P3_Size_p
	  section.data(175).logicalSrcIdx = 186;
	  section.data(175).dtTransOffset = 231;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P3_d
	  section.data(176).logicalSrcIdx = 187;
	  section.data(176).dtTransOffset = 233;
	
	  ;% Callibration_check_Robot_Ipos_P.Dct1lowpass_P1_Size_a
	  section.data(177).logicalSrcIdx = 188;
	  section.data(177).dtTransOffset = 234;
	
	  ;% Callibration_check_Robot_Ipos_P.Dct1lowpass_P1_k
	  section.data(178).logicalSrcIdx = 189;
	  section.data(178).dtTransOffset = 236;
	
	  ;% Callibration_check_Robot_Ipos_P.Dct1lowpass_P2_Size_p
	  section.data(179).logicalSrcIdx = 190;
	  section.data(179).dtTransOffset = 237;
	
	  ;% Callibration_check_Robot_Ipos_P.Dct1lowpass_P2_e5
	  section.data(180).logicalSrcIdx = 191;
	  section.data(180).dtTransOffset = 239;
	
	  ;% Callibration_check_Robot_Ipos_P.Gain_Gain_f
	  section.data(181).logicalSrcIdx = 192;
	  section.data(181).dtTransOffset = 240;
	
	  ;% Callibration_check_Robot_Ipos_P.Saturation_UpperSat_p
	  section.data(182).logicalSrcIdx = 193;
	  section.data(182).dtTransOffset = 241;
	
	  ;% Callibration_check_Robot_Ipos_P.Saturation_LowerSat_h
	  section.data(183).logicalSrcIdx = 194;
	  section.data(183).dtTransOffset = 242;
	
	  ;% Callibration_check_Robot_Ipos_P.ResetEncoderR1_P1_Size_j
	  section.data(184).logicalSrcIdx = 195;
	  section.data(184).dtTransOffset = 243;
	
	  ;% Callibration_check_Robot_Ipos_P.ResetEncoderR1_P1_o
	  section.data(185).logicalSrcIdx = 196;
	  section.data(185).dtTransOffset = 245;
	
	  ;% Callibration_check_Robot_Ipos_P.DiscreteTimeIntegrator_gainv_mz
	  section.data(186).logicalSrcIdx = 197;
	  section.data(186).dtTransOffset = 246;
	
	  ;% Callibration_check_Robot_Ipos_P.DiscreteTimeIntegrator_IC_h
	  section.data(187).logicalSrcIdx = 198;
	  section.data(187).dtTransOffset = 247;
	
	  ;% Callibration_check_Robot_Ipos_P.Gain1_Gain_gc
	  section.data(188).logicalSrcIdx = 199;
	  section.data(188).dtTransOffset = 248;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctintegrator3_P1_Size_c
	  section.data(189).logicalSrcIdx = 200;
	  section.data(189).dtTransOffset = 249;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctintegrator3_P1_i
	  section.data(190).logicalSrcIdx = 201;
	  section.data(190).dtTransOffset = 251;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctintegrator3_P2_Size_h
	  section.data(191).logicalSrcIdx = 202;
	  section.data(191).dtTransOffset = 252;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctintegrator3_P2_o
	  section.data(192).logicalSrcIdx = 203;
	  section.data(192).dtTransOffset = 254;
	
	  ;% Callibration_check_Robot_Ipos_P.Dct1lowpass_P1_Size_i
	  section.data(193).logicalSrcIdx = 204;
	  section.data(193).dtTransOffset = 255;
	
	  ;% Callibration_check_Robot_Ipos_P.Dct1lowpass_P1_j
	  section.data(194).logicalSrcIdx = 205;
	  section.data(194).dtTransOffset = 257;
	
	  ;% Callibration_check_Robot_Ipos_P.Dct1lowpass_P2_Size_d
	  section.data(195).logicalSrcIdx = 206;
	  section.data(195).dtTransOffset = 258;
	
	  ;% Callibration_check_Robot_Ipos_P.Dct1lowpass_P2_h
	  section.data(196).logicalSrcIdx = 207;
	  section.data(196).dtTransOffset = 260;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P1_Size_d
	  section.data(197).logicalSrcIdx = 208;
	  section.data(197).dtTransOffset = 261;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P1_f
	  section.data(198).logicalSrcIdx = 209;
	  section.data(198).dtTransOffset = 263;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P2_Size_g5
	  section.data(199).logicalSrcIdx = 210;
	  section.data(199).dtTransOffset = 264;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P2_go
	  section.data(200).logicalSrcIdx = 211;
	  section.data(200).dtTransOffset = 266;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P3_Size_i
	  section.data(201).logicalSrcIdx = 212;
	  section.data(201).dtTransOffset = 267;
	
	  ;% Callibration_check_Robot_Ipos_P.Dctleadlag_P3_b
	  section.data(202).logicalSrcIdx = 213;
	  section.data(202).dtTransOffset = 269;
	
	  ;% Callibration_check_Robot_Ipos_P.HomingRunningSwitch_Threshold_i
	  section.data(203).logicalSrcIdx = 214;
	  section.data(203).dtTransOffset = 270;
	
	  ;% Callibration_check_Robot_Ipos_P.Gain_Gain_fm
	  section.data(204).logicalSrcIdx = 215;
	  section.data(204).dtTransOffset = 271;
	
	  ;% Callibration_check_Robot_Ipos_P.Constant1_Value_n
	  section.data(205).logicalSrcIdx = 216;
	  section.data(205).dtTransOffset = 272;
	
	  ;% Callibration_check_Robot_Ipos_P.LimitSpeed_RisingLim
	  section.data(206).logicalSrcIdx = 217;
	  section.data(206).dtTransOffset = 273;
	
	  ;% Callibration_check_Robot_Ipos_P.LimitSpeed_FallingLim
	  section.data(207).logicalSrcIdx = 218;
	  section.data(207).dtTransOffset = 274;
	
	  ;% Callibration_check_Robot_Ipos_P.LimitSpeed_IC
	  section.data(208).logicalSrcIdx = 219;
	  section.data(208).dtTransOffset = 275;
	
	  ;% Callibration_check_Robot_Ipos_P.TSamp_WtEt
	  section.data(209).logicalSrcIdx = 220;
	  section.data(209).dtTransOffset = 276;
	
	  ;% Callibration_check_Robot_Ipos_P.LimitAcceleration_RisingLim
	  section.data(210).logicalSrcIdx = 221;
	  section.data(210).dtTransOffset = 277;
	
	  ;% Callibration_check_Robot_Ipos_P.LimitAcceleration_FallingLim
	  section.data(211).logicalSrcIdx = 222;
	  section.data(211).dtTransOffset = 278;
	
	  ;% Callibration_check_Robot_Ipos_P.LimitAcceleration_IC
	  section.data(212).logicalSrcIdx = 223;
	  section.data(212).dtTransOffset = 279;
	
	  ;% Callibration_check_Robot_Ipos_P.DiscreteTimeIntegrator_gainva_f
	  section.data(213).logicalSrcIdx = 224;
	  section.data(213).dtTransOffset = 280;
	
	  ;% Callibration_check_Robot_Ipos_P.TSamp_WtEt_h
	  section.data(214).logicalSrcIdx = 225;
	  section.data(214).dtTransOffset = 281;
	
	  ;% Callibration_check_Robot_Ipos_P.Constant1_Value_b
	  section.data(215).logicalSrcIdx = 226;
	  section.data(215).dtTransOffset = 282;
	
	  ;% Callibration_check_Robot_Ipos_P.LimitSpeed_RisingLim_l
	  section.data(216).logicalSrcIdx = 227;
	  section.data(216).dtTransOffset = 283;
	
	  ;% Callibration_check_Robot_Ipos_P.LimitSpeed_FallingLim_j
	  section.data(217).logicalSrcIdx = 228;
	  section.data(217).dtTransOffset = 284;
	
	  ;% Callibration_check_Robot_Ipos_P.LimitSpeed_IC_m
	  section.data(218).logicalSrcIdx = 229;
	  section.data(218).dtTransOffset = 285;
	
	  ;% Callibration_check_Robot_Ipos_P.TSamp_WtEt_f
	  section.data(219).logicalSrcIdx = 230;
	  section.data(219).dtTransOffset = 286;
	
	  ;% Callibration_check_Robot_Ipos_P.LimitAcceleration_RisingLim_k
	  section.data(220).logicalSrcIdx = 231;
	  section.data(220).dtTransOffset = 287;
	
	  ;% Callibration_check_Robot_Ipos_P.LimitAcceleration_FallingLim_l
	  section.data(221).logicalSrcIdx = 232;
	  section.data(221).dtTransOffset = 288;
	
	  ;% Callibration_check_Robot_Ipos_P.LimitAcceleration_IC_h
	  section.data(222).logicalSrcIdx = 233;
	  section.data(222).dtTransOffset = 289;
	
	  ;% Callibration_check_Robot_Ipos_P.DiscreteTimeIntegrator_gainva_l
	  section.data(223).logicalSrcIdx = 234;
	  section.data(223).dtTransOffset = 290;
	
	  ;% Callibration_check_Robot_Ipos_P.TSamp_WtEt_k
	  section.data(224).logicalSrcIdx = 235;
	  section.data(224).dtTransOffset = 291;
	
	  ;% Callibration_check_Robot_Ipos_P.Constant1_Value_k
	  section.data(225).logicalSrcIdx = 236;
	  section.data(225).dtTransOffset = 292;
	
	  ;% Callibration_check_Robot_Ipos_P.LimitSpeed_RisingLim_a
	  section.data(226).logicalSrcIdx = 237;
	  section.data(226).dtTransOffset = 293;
	
	  ;% Callibration_check_Robot_Ipos_P.LimitSpeed_FallingLim_i
	  section.data(227).logicalSrcIdx = 238;
	  section.data(227).dtTransOffset = 294;
	
	  ;% Callibration_check_Robot_Ipos_P.LimitSpeed_IC_j
	  section.data(228).logicalSrcIdx = 239;
	  section.data(228).dtTransOffset = 295;
	
	  ;% Callibration_check_Robot_Ipos_P.TSamp_WtEt_p
	  section.data(229).logicalSrcIdx = 240;
	  section.data(229).dtTransOffset = 296;
	
	  ;% Callibration_check_Robot_Ipos_P.LimitAcceleration_RisingLim_n
	  section.data(230).logicalSrcIdx = 241;
	  section.data(230).dtTransOffset = 297;
	
	  ;% Callibration_check_Robot_Ipos_P.LimitAcceleration_FallingLim_n
	  section.data(231).logicalSrcIdx = 242;
	  section.data(231).dtTransOffset = 298;
	
	  ;% Callibration_check_Robot_Ipos_P.LimitAcceleration_IC_j
	  section.data(232).logicalSrcIdx = 243;
	  section.data(232).dtTransOffset = 299;
	
	  ;% Callibration_check_Robot_Ipos_P.DiscreteTimeIntegrator_gainva_c
	  section.data(233).logicalSrcIdx = 244;
	  section.data(233).dtTransOffset = 300;
	
	  ;% Callibration_check_Robot_Ipos_P.TSamp_WtEt_g
	  section.data(234).logicalSrcIdx = 245;
	  section.data(234).dtTransOffset = 301;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_P.LEDRing_Y0
	  section.data(1).logicalSrcIdx = 246;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Callibration_check_Robot_Ipos_P.Colorsetwithstringblackorwhite_
	  section.data(2).logicalSrcIdx = 247;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Callibration_check_Robot_Ipos_P.Colorspecifiedin6hexdigitsrrggb
	  section.data(3).logicalSrcIdx = 248;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Callibration_check_Robot_Ipos_P.StringConstant3_String
	  section.data(4).logicalSrcIdx = 249;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Callibration_check_Robot_Ipos_P.StringConstant1_String
	  section.data(5).logicalSrcIdx = 250;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Callibration_check_Robot_Ipos_P.StringConstant4_String
	  section.data(6).logicalSrcIdx = 251;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Callibration_check_Robot_Ipos_P.ReadyGreen_String
	  section.data(7).logicalSrcIdx = 252;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Callibration_check_Robot_Ipos_P.AirbagRed_String
	  section.data(8).logicalSrcIdx = 253;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Callibration_check_Robot_Ipos_P.HomingOrange_String
	  section.data(9).logicalSrcIdx = 254;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Callibration_check_Robot_Ipos_P.Delay_InitialCondition
	  section.data(10).logicalSrcIdx = 255;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_P.ManualSwitch_CurrentSetting
	  section.data(1).logicalSrcIdx = 256;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Callibration_check_Robot_Ipos_P.ManualSwitch1_CurrentSetting
	  section.data(2).logicalSrcIdx = 257;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Callibration_check_Robot_Ipos_P.Constant1_Value_l
	  section.data(3).logicalSrcIdx = 258;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Callibration_check_Robot_Ipos_P.Constant_Value_b
	  section.data(4).logicalSrcIdx = 259;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
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
    nTotSects     = 6;
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
    ;% Auto data (Callibration_check_Robot_Ipos_B)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_B.ManualSwitch1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 128;
      section.data(128)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_B.SFunction
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Callibration_check_Robot_Ipos_B.ec_Ipos_o1
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Callibration_check_Robot_Ipos_B.ec_Ipos_o2
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Callibration_check_Robot_Ipos_B.ec_Ipos_o3
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Callibration_check_Robot_Ipos_B.ec_Ipos_o4
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Callibration_check_Robot_Ipos_B.ec_Ipos_o5
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Callibration_check_Robot_Ipos_B.Gain
	  section.data(7).logicalSrcIdx = 7;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Callibration_check_Robot_Ipos_B.set_robot_calibration_r
	  section.data(8).logicalSrcIdx = 8;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Callibration_check_Robot_Ipos_B.Constant1
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Callibration_check_Robot_Ipos_B.DiscreteTimeIntegrator
	  section.data(10).logicalSrcIdx = 10;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Callibration_check_Robot_Ipos_B.Sum
	  section.data(11).logicalSrcIdx = 11;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Callibration_check_Robot_Ipos_B.Sum2
	  section.data(12).logicalSrcIdx = 12;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Callibration_check_Robot_Ipos_B.Gain1
	  section.data(13).logicalSrcIdx = 13;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Callibration_check_Robot_Ipos_B.DiscreteTimeIntegrator_g
	  section.data(14).logicalSrcIdx = 14;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Callibration_check_Robot_Ipos_B.set_robot_calibration_x
	  section.data(15).logicalSrcIdx = 15;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Callibration_check_Robot_Ipos_B.Constant1_p
	  section.data(16).logicalSrcIdx = 16;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Callibration_check_Robot_Ipos_B.Sum_a
	  section.data(17).logicalSrcIdx = 17;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Callibration_check_Robot_Ipos_B.Sum2_f
	  section.data(18).logicalSrcIdx = 18;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Callibration_check_Robot_Ipos_B.Gain2
	  section.data(19).logicalSrcIdx = 19;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Callibration_check_Robot_Ipos_B.set_robot_calibration_z
	  section.data(20).logicalSrcIdx = 20;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Callibration_check_Robot_Ipos_B.Constant1_c
	  section.data(21).logicalSrcIdx = 21;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Callibration_check_Robot_Ipos_B.Sum_n
	  section.data(22).logicalSrcIdx = 22;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Callibration_check_Robot_Ipos_B.Sum2_k
	  section.data(23).logicalSrcIdx = 23;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Callibration_check_Robot_Ipos_B.Add1
	  section.data(24).logicalSrcIdx = 24;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Callibration_check_Robot_Ipos_B.Gain3
	  section.data(25).logicalSrcIdx = 25;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Callibration_check_Robot_Ipos_B.Gain_b
	  section.data(26).logicalSrcIdx = 26;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Callibration_check_Robot_Ipos_B.Dctintegrator
	  section.data(27).logicalSrcIdx = 27;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Callibration_check_Robot_Ipos_B.Dctleadlag
	  section.data(28).logicalSrcIdx = 28;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Callibration_check_Robot_Ipos_B.Dct1lowpass
	  section.data(29).logicalSrcIdx = 29;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Callibration_check_Robot_Ipos_B.Product
	  section.data(30).logicalSrcIdx = 30;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Callibration_check_Robot_Ipos_B.HomingRunningSwitch
	  section.data(31).logicalSrcIdx = 31;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Callibration_check_Robot_Ipos_B.Gain_h
	  section.data(32).logicalSrcIdx = 32;
	  section.data(32).dtTransOffset = 31;
	
	  ;% Callibration_check_Robot_Ipos_B.Dctleadlag_h
	  section.data(33).logicalSrcIdx = 33;
	  section.data(33).dtTransOffset = 32;
	
	  ;% Callibration_check_Robot_Ipos_B.Dct1lowpass_f
	  section.data(34).logicalSrcIdx = 34;
	  section.data(34).dtTransOffset = 33;
	
	  ;% Callibration_check_Robot_Ipos_B.AirbagSwitch
	  section.data(35).logicalSrcIdx = 35;
	  section.data(35).dtTransOffset = 34;
	
	  ;% Callibration_check_Robot_Ipos_B.Product1
	  section.data(36).logicalSrcIdx = 36;
	  section.data(36).dtTransOffset = 35;
	
	  ;% Callibration_check_Robot_Ipos_B.Gain1_l
	  section.data(37).logicalSrcIdx = 37;
	  section.data(37).dtTransOffset = 36;
	
	  ;% Callibration_check_Robot_Ipos_B.Gain1_m
	  section.data(38).logicalSrcIdx = 38;
	  section.data(38).dtTransOffset = 37;
	
	  ;% Callibration_check_Robot_Ipos_B.Dctintegrator_o
	  section.data(39).logicalSrcIdx = 39;
	  section.data(39).dtTransOffset = 38;
	
	  ;% Callibration_check_Robot_Ipos_B.Dctleadlag_m
	  section.data(40).logicalSrcIdx = 40;
	  section.data(40).dtTransOffset = 39;
	
	  ;% Callibration_check_Robot_Ipos_B.Dct1lowpass_o
	  section.data(41).logicalSrcIdx = 41;
	  section.data(41).dtTransOffset = 40;
	
	  ;% Callibration_check_Robot_Ipos_B.Gain1_f
	  section.data(42).logicalSrcIdx = 42;
	  section.data(42).dtTransOffset = 41;
	
	  ;% Callibration_check_Robot_Ipos_B.Dctleadlag_d
	  section.data(43).logicalSrcIdx = 43;
	  section.data(43).dtTransOffset = 42;
	
	  ;% Callibration_check_Robot_Ipos_B.Dct1lowpass_d
	  section.data(44).logicalSrcIdx = 44;
	  section.data(44).dtTransOffset = 43;
	
	  ;% Callibration_check_Robot_Ipos_B.Saturation1
	  section.data(45).logicalSrcIdx = 45;
	  section.data(45).dtTransOffset = 44;
	
	  ;% Callibration_check_Robot_Ipos_B.Gain_f
	  section.data(46).logicalSrcIdx = 46;
	  section.data(46).dtTransOffset = 45;
	
	  ;% Callibration_check_Robot_Ipos_B.Dctintegrator_l
	  section.data(47).logicalSrcIdx = 47;
	  section.data(47).dtTransOffset = 46;
	
	  ;% Callibration_check_Robot_Ipos_B.Dctleadlag_dv
	  section.data(48).logicalSrcIdx = 48;
	  section.data(48).dtTransOffset = 47;
	
	  ;% Callibration_check_Robot_Ipos_B.Dct1lowpass_a
	  section.data(49).logicalSrcIdx = 49;
	  section.data(49).dtTransOffset = 48;
	
	  ;% Callibration_check_Robot_Ipos_B.Gain_l
	  section.data(50).logicalSrcIdx = 50;
	  section.data(50).dtTransOffset = 49;
	
	  ;% Callibration_check_Robot_Ipos_B.Dctleadlag_g
	  section.data(51).logicalSrcIdx = 51;
	  section.data(51).dtTransOffset = 50;
	
	  ;% Callibration_check_Robot_Ipos_B.Dct1lowpass_aa
	  section.data(52).logicalSrcIdx = 52;
	  section.data(52).dtTransOffset = 51;
	
	  ;% Callibration_check_Robot_Ipos_B.Saturation
	  section.data(53).logicalSrcIdx = 53;
	  section.data(53).dtTransOffset = 52;
	
	  ;% Callibration_check_Robot_Ipos_B.DiscreteTimeIntegrator_m
	  section.data(54).logicalSrcIdx = 54;
	  section.data(54).dtTransOffset = 53;
	
	  ;% Callibration_check_Robot_Ipos_B.Gain1_k
	  section.data(55).logicalSrcIdx = 55;
	  section.data(55).dtTransOffset = 54;
	
	  ;% Callibration_check_Robot_Ipos_B.Dctintegrator3
	  section.data(56).logicalSrcIdx = 56;
	  section.data(56).dtTransOffset = 55;
	
	  ;% Callibration_check_Robot_Ipos_B.Dct1lowpass_g
	  section.data(57).logicalSrcIdx = 57;
	  section.data(57).dtTransOffset = 56;
	
	  ;% Callibration_check_Robot_Ipos_B.Dctleadlag_a
	  section.data(58).logicalSrcIdx = 58;
	  section.data(58).dtTransOffset = 57;
	
	  ;% Callibration_check_Robot_Ipos_B.HomingRunningSwitch_i
	  section.data(59).logicalSrcIdx = 59;
	  section.data(59).dtTransOffset = 58;
	
	  ;% Callibration_check_Robot_Ipos_B.Gain_lu
	  section.data(60).logicalSrcIdx = 60;
	  section.data(60).dtTransOffset = 59;
	
	  ;% Callibration_check_Robot_Ipos_B.Constant1_g
	  section.data(61).logicalSrcIdx = 61;
	  section.data(61).dtTransOffset = 60;
	
	  ;% Callibration_check_Robot_Ipos_B.DiscreteTimeIntegrator_l
	  section.data(62).logicalSrcIdx = 62;
	  section.data(62).dtTransOffset = 61;
	
	  ;% Callibration_check_Robot_Ipos_B.Constant1_a
	  section.data(63).logicalSrcIdx = 63;
	  section.data(63).dtTransOffset = 62;
	
	  ;% Callibration_check_Robot_Ipos_B.DiscreteTimeIntegrator_my
	  section.data(64).logicalSrcIdx = 64;
	  section.data(64).dtTransOffset = 63;
	
	  ;% Callibration_check_Robot_Ipos_B.Constant1_p4
	  section.data(65).logicalSrcIdx = 65;
	  section.data(65).dtTransOffset = 64;
	
	  ;% Callibration_check_Robot_Ipos_B.DiscreteTimeIntegrator_e
	  section.data(66).logicalSrcIdx = 66;
	  section.data(66).dtTransOffset = 65;
	
	  ;% Callibration_check_Robot_Ipos_B.jogSpeed
	  section.data(67).logicalSrcIdx = 67;
	  section.data(67).dtTransOffset = 66;
	
	  ;% Callibration_check_Robot_Ipos_B.homeControllerEnabled
	  section.data(68).logicalSrcIdx = 68;
	  section.data(68).dtTransOffset = 67;
	
	  ;% Callibration_check_Robot_Ipos_B.resetEnc
	  section.data(69).logicalSrcIdx = 69;
	  section.data(69).dtTransOffset = 68;
	
	  ;% Callibration_check_Robot_Ipos_B.homingBusy
	  section.data(70).logicalSrcIdx = 70;
	  section.data(70).dtTransOffset = 69;
	
	  ;% Callibration_check_Robot_Ipos_B.Ready
	  section.data(71).logicalSrcIdx = 71;
	  section.data(71).dtTransOffset = 70;
	
	  ;% Callibration_check_Robot_Ipos_B.StopSim
	  section.data(72).logicalSrcIdx = 72;
	  section.data(72).dtTransOffset = 71;
	
	  ;% Callibration_check_Robot_Ipos_B.jogSpeed_a
	  section.data(73).logicalSrcIdx = 73;
	  section.data(73).dtTransOffset = 72;
	
	  ;% Callibration_check_Robot_Ipos_B.toPoint
	  section.data(74).logicalSrcIdx = 74;
	  section.data(74).dtTransOffset = 73;
	
	  ;% Callibration_check_Robot_Ipos_B.homeControllerEnabled_m
	  section.data(75).logicalSrcIdx = 75;
	  section.data(75).dtTransOffset = 74;
	
	  ;% Callibration_check_Robot_Ipos_B.resetEnc_l
	  section.data(76).logicalSrcIdx = 76;
	  section.data(76).dtTransOffset = 75;
	
	  ;% Callibration_check_Robot_Ipos_B.homingBusy_c
	  section.data(77).logicalSrcIdx = 77;
	  section.data(77).dtTransOffset = 76;
	
	  ;% Callibration_check_Robot_Ipos_B.freddy
	  section.data(78).logicalSrcIdx = 78;
	  section.data(78).dtTransOffset = 77;
	
	  ;% Callibration_check_Robot_Ipos_B.airBagEnabled
	  section.data(79).logicalSrcIdx = 79;
	  section.data(79).dtTransOffset = 78;
	
	  ;% Callibration_check_Robot_Ipos_B.airBagRef
	  section.data(80).logicalSrcIdx = 80;
	  section.data(80).dtTransOffset = 79;
	
	  ;% Callibration_check_Robot_Ipos_B.controlEnabled
	  section.data(81).logicalSrcIdx = 81;
	  section.data(81).dtTransOffset = 80;
	
	  ;% Callibration_check_Robot_Ipos_B.Ready_a
	  section.data(82).logicalSrcIdx = 82;
	  section.data(82).dtTransOffset = 81;
	
	  ;% Callibration_check_Robot_Ipos_B.StopSim_n
	  section.data(83).logicalSrcIdx = 83;
	  section.data(83).dtTransOffset = 82;
	
	  ;% Callibration_check_Robot_Ipos_B.y
	  section.data(84).logicalSrcIdx = 84;
	  section.data(84).dtTransOffset = 83;
	
	  ;% Callibration_check_Robot_Ipos_B.jogSpeed_l
	  section.data(85).logicalSrcIdx = 85;
	  section.data(85).dtTransOffset = 84;
	
	  ;% Callibration_check_Robot_Ipos_B.toPoint_j
	  section.data(86).logicalSrcIdx = 86;
	  section.data(86).dtTransOffset = 85;
	
	  ;% Callibration_check_Robot_Ipos_B.homeControllerEnabled_c
	  section.data(87).logicalSrcIdx = 87;
	  section.data(87).dtTransOffset = 86;
	
	  ;% Callibration_check_Robot_Ipos_B.resetEnc_ln
	  section.data(88).logicalSrcIdx = 88;
	  section.data(88).dtTransOffset = 87;
	
	  ;% Callibration_check_Robot_Ipos_B.freddy_a
	  section.data(89).logicalSrcIdx = 89;
	  section.data(89).dtTransOffset = 88;
	
	  ;% Callibration_check_Robot_Ipos_B.homingBusy_p
	  section.data(90).logicalSrcIdx = 90;
	  section.data(90).dtTransOffset = 89;
	
	  ;% Callibration_check_Robot_Ipos_B.airBagEnabled_a
	  section.data(91).logicalSrcIdx = 91;
	  section.data(91).dtTransOffset = 90;
	
	  ;% Callibration_check_Robot_Ipos_B.airBagRef_l
	  section.data(92).logicalSrcIdx = 92;
	  section.data(92).dtTransOffset = 91;
	
	  ;% Callibration_check_Robot_Ipos_B.controlEnabled_i
	  section.data(93).logicalSrcIdx = 93;
	  section.data(93).dtTransOffset = 92;
	
	  ;% Callibration_check_Robot_Ipos_B.Ready_f
	  section.data(94).logicalSrcIdx = 94;
	  section.data(94).dtTransOffset = 93;
	
	  ;% Callibration_check_Robot_Ipos_B.StopSim_o
	  section.data(95).logicalSrcIdx = 95;
	  section.data(95).dtTransOffset = 94;
	
	  ;% Callibration_check_Robot_Ipos_B.jogSpeed_j
	  section.data(96).logicalSrcIdx = 96;
	  section.data(96).dtTransOffset = 95;
	
	  ;% Callibration_check_Robot_Ipos_B.toPoint_jr
	  section.data(97).logicalSrcIdx = 97;
	  section.data(97).dtTransOffset = 96;
	
	  ;% Callibration_check_Robot_Ipos_B.homeControllerEnabled_d
	  section.data(98).logicalSrcIdx = 98;
	  section.data(98).dtTransOffset = 97;
	
	  ;% Callibration_check_Robot_Ipos_B.resetEnc_b
	  section.data(99).logicalSrcIdx = 99;
	  section.data(99).dtTransOffset = 98;
	
	  ;% Callibration_check_Robot_Ipos_B.freddy_m
	  section.data(100).logicalSrcIdx = 100;
	  section.data(100).dtTransOffset = 99;
	
	  ;% Callibration_check_Robot_Ipos_B.homingBusy_a
	  section.data(101).logicalSrcIdx = 101;
	  section.data(101).dtTransOffset = 100;
	
	  ;% Callibration_check_Robot_Ipos_B.airBagEnabled_f
	  section.data(102).logicalSrcIdx = 102;
	  section.data(102).dtTransOffset = 101;
	
	  ;% Callibration_check_Robot_Ipos_B.airBagRef_lc
	  section.data(103).logicalSrcIdx = 103;
	  section.data(103).dtTransOffset = 102;
	
	  ;% Callibration_check_Robot_Ipos_B.controlEnabled_f
	  section.data(104).logicalSrcIdx = 104;
	  section.data(104).dtTransOffset = 103;
	
	  ;% Callibration_check_Robot_Ipos_B.Ready_j
	  section.data(105).logicalSrcIdx = 105;
	  section.data(105).dtTransOffset = 104;
	
	  ;% Callibration_check_Robot_Ipos_B.StopSim_e
	  section.data(106).logicalSrcIdx = 106;
	  section.data(106).dtTransOffset = 105;
	
	  ;% Callibration_check_Robot_Ipos_B.y_g
	  section.data(107).logicalSrcIdx = 107;
	  section.data(107).dtTransOffset = 106;
	
	  ;% Callibration_check_Robot_Ipos_B.Selector2
	  section.data(108).logicalSrcIdx = 108;
	  section.data(108).dtTransOffset = 107;
	
	  ;% Callibration_check_Robot_Ipos_B.Selector
	  section.data(109).logicalSrcIdx = 109;
	  section.data(109).dtTransOffset = 116;
	
	  ;% Callibration_check_Robot_Ipos_B.Conveyorreferencemm
	  section.data(110).logicalSrcIdx = 110;
	  section.data(110).dtTransOffset = 119;
	
	  ;% Callibration_check_Robot_Ipos_B.Gain1_c
	  section.data(111).logicalSrcIdx = 111;
	  section.data(111).dtTransOffset = 120;
	
	  ;% Callibration_check_Robot_Ipos_B.Dctintegrator3_c
	  section.data(112).logicalSrcIdx = 112;
	  section.data(112).dtTransOffset = 121;
	
	  ;% Callibration_check_Robot_Ipos_B.Dct1lowpass_l
	  section.data(113).logicalSrcIdx = 113;
	  section.data(113).dtTransOffset = 122;
	
	  ;% Callibration_check_Robot_Ipos_B.Dctleadlag_f
	  section.data(114).logicalSrcIdx = 114;
	  section.data(114).dtTransOffset = 123;
	
	  ;% Callibration_check_Robot_Ipos_B.SFunctionBuilder
	  section.data(115).logicalSrcIdx = 115;
	  section.data(115).dtTransOffset = 124;
	
	  ;% Callibration_check_Robot_Ipos_B.Sum_g
	  section.data(116).logicalSrcIdx = 116;
	  section.data(116).dtTransOffset = 125;
	
	  ;% Callibration_check_Robot_Ipos_B.SignalConversion2
	  section.data(117).logicalSrcIdx = 117;
	  section.data(117).dtTransOffset = 126;
	
	  ;% Callibration_check_Robot_Ipos_B.SignalConversion1
	  section.data(118).logicalSrcIdx = 118;
	  section.data(118).dtTransOffset = 127;
	
	  ;% Callibration_check_Robot_Ipos_B.SignalConversion
	  section.data(119).logicalSrcIdx = 119;
	  section.data(119).dtTransOffset = 128;
	
	  ;% Callibration_check_Robot_Ipos_B.Sum4
	  section.data(120).logicalSrcIdx = 120;
	  section.data(120).dtTransOffset = 129;
	
	  ;% Callibration_check_Robot_Ipos_B.Sum5
	  section.data(121).logicalSrcIdx = 121;
	  section.data(121).dtTransOffset = 130;
	
	  ;% Callibration_check_Robot_Ipos_B.Sum6
	  section.data(122).logicalSrcIdx = 122;
	  section.data(122).dtTransOffset = 131;
	
	  ;% Callibration_check_Robot_Ipos_B.Gain1_n
	  section.data(123).logicalSrcIdx = 123;
	  section.data(123).dtTransOffset = 132;
	
	  ;% Callibration_check_Robot_Ipos_B.Doubleclickswitch
	  section.data(124).logicalSrcIdx = 124;
	  section.data(124).dtTransOffset = 133;
	
	  ;% Callibration_check_Robot_Ipos_B.Object
	  section.data(125).logicalSrcIdx = 125;
	  section.data(125).dtTransOffset = 134;
	
	  ;% Callibration_check_Robot_Ipos_B.Plot
	  section.data(126).logicalSrcIdx = 126;
	  section.data(126).dtTransOffset = 135;
	
	  ;% Callibration_check_Robot_Ipos_B.Stop
	  section.data(127).logicalSrcIdx = 127;
	  section.data(127).dtTransOffset = 136;
	
	  ;% Callibration_check_Robot_Ipos_B.In1
	  section.data(128).logicalSrcIdx = 135;
	  section.data(128).dtTransOffset = 137;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_B.RelationalOperator
	  section.data(1).logicalSrcIdx = 137;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Callibration_check_Robot_Ipos_B.RelationalOperator_m
	  section.data(2).logicalSrcIdx = 138;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Callibration_check_Robot_Ipos_B.RelationalOperator_e
	  section.data(3).logicalSrcIdx = 139;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Callibration_check_Robot_Ipos_B.Compare
	  section.data(4).logicalSrcIdx = 140;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Callibration_check_Robot_Ipos_B.Compare_c
	  section.data(5).logicalSrcIdx = 141;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_B.sf_MATLABFunction1.path
	  section.data(1).logicalSrcIdx = 142;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_B.sf_MATLABFunction.path
	  section.data(1).logicalSrcIdx = 143;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_B.sf_MATLABFunction2.path
	  section.data(1).logicalSrcIdx = 144;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
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
    nTotSects     = 26;
    sectIdxOffset = 6;
    
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
    ;% Auto data (Callibration_check_Robot_Ipos_DW)
    ;%
      section.nData     = 20;
      section.data(20)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_DW.DiscreteTimeIntegrator_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Callibration_check_Robot_Ipos_DW.DiscreteTimeIntegrator_DSTATE_e
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Callibration_check_Robot_Ipos_DW.DiscreteTimeIntegrator_DSTATE_c
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Callibration_check_Robot_Ipos_DW.DiscreteTimeIntegrator_DSTATE_d
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Callibration_check_Robot_Ipos_DW.DiscreteTimeIntegrator_DSTAT_ef
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Callibration_check_Robot_Ipos_DW.DiscreteTimeIntegrator_DSTAT_ei
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Callibration_check_Robot_Ipos_DW.UnitDelay_DSTATE
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Callibration_check_Robot_Ipos_DW.UnitDelay1_DSTATE
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Callibration_check_Robot_Ipos_DW.DiscreteTimeIntegrator_DSTAT_dx
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Callibration_check_Robot_Ipos_DW.UD_DSTATE
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Callibration_check_Robot_Ipos_DW.DiscreteTimeIntegrator_DSTATE_p
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Callibration_check_Robot_Ipos_DW.UD_DSTATE_n
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Callibration_check_Robot_Ipos_DW.UD_DSTATE_d
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Callibration_check_Robot_Ipos_DW.DiscreteTimeIntegrator_DSTAT_eh
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Callibration_check_Robot_Ipos_DW.UD_DSTATE_i
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Callibration_check_Robot_Ipos_DW.UD_DSTATE_a
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Callibration_check_Robot_Ipos_DW.DiscreteTimeIntegrator_DSTATE_o
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Callibration_check_Robot_Ipos_DW.UD_DSTATE_c
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Callibration_check_Robot_Ipos_DW.DelayInput1_DSTATE
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Callibration_check_Robot_Ipos_DW.Discreteintegrator_DSTATE
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 30;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_DW.Delay_DSTATE
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 31;
      section.data(31)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_DW.PrevY
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Callibration_check_Robot_Ipos_DW.PrevY_j
	  section.data(2).logicalSrcIdx = 22;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Callibration_check_Robot_Ipos_DW.PrevY_p
	  section.data(3).logicalSrcIdx = 23;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Callibration_check_Robot_Ipos_DW.PrevY_m
	  section.data(4).logicalSrcIdx = 24;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Callibration_check_Robot_Ipos_DW.PrevY_i
	  section.data(5).logicalSrcIdx = 25;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Callibration_check_Robot_Ipos_DW.PrevY_g
	  section.data(6).logicalSrcIdx = 26;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Callibration_check_Robot_Ipos_DW.currentcarPos
	  section.data(7).logicalSrcIdx = 27;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Callibration_check_Robot_Ipos_DW.currentcarPos_f
	  section.data(8).logicalSrcIdx = 28;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Callibration_check_Robot_Ipos_DW.currentcarPos_k
	  section.data(9).logicalSrcIdx = 29;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Callibration_check_Robot_Ipos_DW.fileID
	  section.data(10).logicalSrcIdx = 30;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Callibration_check_Robot_Ipos_DW.Dctintegrator_RWORK
	  section.data(11).logicalSrcIdx = 31;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Callibration_check_Robot_Ipos_DW.Dctleadlag_RWORK
	  section.data(12).logicalSrcIdx = 32;
	  section.data(12).dtTransOffset = 12;
	
	  ;% Callibration_check_Robot_Ipos_DW.Dct1lowpass_RWORK
	  section.data(13).logicalSrcIdx = 33;
	  section.data(13).dtTransOffset = 14;
	
	  ;% Callibration_check_Robot_Ipos_DW.Dctleadlag_RWORK_m
	  section.data(14).logicalSrcIdx = 34;
	  section.data(14).dtTransOffset = 16;
	
	  ;% Callibration_check_Robot_Ipos_DW.Dct1lowpass_RWORK_c
	  section.data(15).logicalSrcIdx = 35;
	  section.data(15).dtTransOffset = 18;
	
	  ;% Callibration_check_Robot_Ipos_DW.Dctintegrator_RWORK_m
	  section.data(16).logicalSrcIdx = 36;
	  section.data(16).dtTransOffset = 20;
	
	  ;% Callibration_check_Robot_Ipos_DW.Dctleadlag_RWORK_e
	  section.data(17).logicalSrcIdx = 37;
	  section.data(17).dtTransOffset = 22;
	
	  ;% Callibration_check_Robot_Ipos_DW.Dct1lowpass_RWORK_m
	  section.data(18).logicalSrcIdx = 38;
	  section.data(18).dtTransOffset = 24;
	
	  ;% Callibration_check_Robot_Ipos_DW.Dctleadlag_RWORK_c
	  section.data(19).logicalSrcIdx = 39;
	  section.data(19).dtTransOffset = 26;
	
	  ;% Callibration_check_Robot_Ipos_DW.Dct1lowpass_RWORK_d
	  section.data(20).logicalSrcIdx = 40;
	  section.data(20).dtTransOffset = 28;
	
	  ;% Callibration_check_Robot_Ipos_DW.Dctintegrator_RWORK_p
	  section.data(21).logicalSrcIdx = 41;
	  section.data(21).dtTransOffset = 30;
	
	  ;% Callibration_check_Robot_Ipos_DW.Dctleadlag_RWORK_et
	  section.data(22).logicalSrcIdx = 42;
	  section.data(22).dtTransOffset = 32;
	
	  ;% Callibration_check_Robot_Ipos_DW.Dct1lowpass_RWORK_e
	  section.data(23).logicalSrcIdx = 43;
	  section.data(23).dtTransOffset = 34;
	
	  ;% Callibration_check_Robot_Ipos_DW.Dctleadlag_RWORK_g
	  section.data(24).logicalSrcIdx = 44;
	  section.data(24).dtTransOffset = 36;
	
	  ;% Callibration_check_Robot_Ipos_DW.Dct1lowpass_RWORK_b
	  section.data(25).logicalSrcIdx = 45;
	  section.data(25).dtTransOffset = 38;
	
	  ;% Callibration_check_Robot_Ipos_DW.Dctintegrator3_RWORK
	  section.data(26).logicalSrcIdx = 46;
	  section.data(26).dtTransOffset = 40;
	
	  ;% Callibration_check_Robot_Ipos_DW.Dct1lowpass_RWORK_en
	  section.data(27).logicalSrcIdx = 47;
	  section.data(27).dtTransOffset = 42;
	
	  ;% Callibration_check_Robot_Ipos_DW.Dctleadlag_RWORK_l
	  section.data(28).logicalSrcIdx = 48;
	  section.data(28).dtTransOffset = 44;
	
	  ;% Callibration_check_Robot_Ipos_DW.Dctintegrator3_RWORK_c
	  section.data(29).logicalSrcIdx = 49;
	  section.data(29).dtTransOffset = 46;
	
	  ;% Callibration_check_Robot_Ipos_DW.Dct1lowpass_RWORK_mc
	  section.data(30).logicalSrcIdx = 50;
	  section.data(30).dtTransOffset = 48;
	
	  ;% Callibration_check_Robot_Ipos_DW.Dctleadlag_RWORK_p
	  section.data(31).logicalSrcIdx = 51;
	  section.data(31).dtTransOffset = 50;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 38;
      section.data(38)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_DW.Scope16_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 52;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope18_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 53;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope20_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 54;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope21_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 55;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope22_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 56;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 57;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope1_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 58;
	  section.data(7).dtTransOffset = 7;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope17_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 59;
	  section.data(8).dtTransOffset = 8;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope6_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 60;
	  section.data(9).dtTransOffset = 9;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope1_PWORK_h.LoggedData
	  section.data(10).logicalSrcIdx = 61;
	  section.data(10).dtTransOffset = 10;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope10_PWORK.LoggedData
	  section.data(11).logicalSrcIdx = 62;
	  section.data(11).dtTransOffset = 11;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope11_PWORK.LoggedData
	  section.data(12).logicalSrcIdx = 63;
	  section.data(12).dtTransOffset = 12;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope19_PWORK.LoggedData
	  section.data(13).logicalSrcIdx = 64;
	  section.data(13).dtTransOffset = 13;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope4_PWORK.LoggedData
	  section.data(14).logicalSrcIdx = 65;
	  section.data(14).dtTransOffset = 14;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope8_PWORK.LoggedData
	  section.data(15).logicalSrcIdx = 66;
	  section.data(15).dtTransOffset = 15;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope14_PWORK.LoggedData
	  section.data(16).logicalSrcIdx = 67;
	  section.data(16).dtTransOffset = 16;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope2_PWORK.LoggedData
	  section.data(17).logicalSrcIdx = 68;
	  section.data(17).dtTransOffset = 17;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope18_PWORK_p.LoggedData
	  section.data(18).logicalSrcIdx = 69;
	  section.data(18).dtTransOffset = 18;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope6_PWORK_h.LoggedData
	  section.data(19).logicalSrcIdx = 70;
	  section.data(19).dtTransOffset = 19;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope2_PWORK_l.LoggedData
	  section.data(20).logicalSrcIdx = 71;
	  section.data(20).dtTransOffset = 20;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope21_PWORK_k.LoggedData
	  section.data(21).logicalSrcIdx = 72;
	  section.data(21).dtTransOffset = 21;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope2_PWORK_n.LoggedData
	  section.data(22).logicalSrcIdx = 73;
	  section.data(22).dtTransOffset = 22;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope22_PWORK_c.LoggedData
	  section.data(23).logicalSrcIdx = 74;
	  section.data(23).dtTransOffset = 23;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope_PWORK_n.LoggedData
	  section.data(24).logicalSrcIdx = 75;
	  section.data(24).dtTransOffset = 24;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope19_PWORK_k.LoggedData
	  section.data(25).logicalSrcIdx = 76;
	  section.data(25).dtTransOffset = 25;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope20_PWORK_a.LoggedData
	  section.data(26).logicalSrcIdx = 77;
	  section.data(26).dtTransOffset = 26;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope16_PWORK_b.LoggedData
	  section.data(27).logicalSrcIdx = 78;
	  section.data(27).dtTransOffset = 27;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope23_PWORK.LoggedData
	  section.data(28).logicalSrcIdx = 79;
	  section.data(28).dtTransOffset = 28;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope_PWORK_p.LoggedData
	  section.data(29).logicalSrcIdx = 80;
	  section.data(29).dtTransOffset = 29;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope3_PWORK.LoggedData
	  section.data(30).logicalSrcIdx = 81;
	  section.data(30).dtTransOffset = 30;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope12_PWORK.LoggedData
	  section.data(31).logicalSrcIdx = 82;
	  section.data(31).dtTransOffset = 31;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope23_PWORK_m.LoggedData
	  section.data(32).logicalSrcIdx = 83;
	  section.data(32).dtTransOffset = 32;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope13_PWORK.LoggedData
	  section.data(33).logicalSrcIdx = 84;
	  section.data(33).dtTransOffset = 34;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope15_PWORK.LoggedData
	  section.data(34).logicalSrcIdx = 85;
	  section.data(34).dtTransOffset = 35;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope7_PWORK.LoggedData
	  section.data(35).logicalSrcIdx = 86;
	  section.data(35).dtTransOffset = 36;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope17_PWORK_n.LoggedData
	  section.data(36).logicalSrcIdx = 87;
	  section.data(36).dtTransOffset = 37;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope_PWORK_f.LoggedData
	  section.data(37).logicalSrcIdx = 88;
	  section.data(37).dtTransOffset = 38;
	
	  ;% Callibration_check_Robot_Ipos_DW.Scope5_PWORK.LoggedData
	  section.data(38).logicalSrcIdx = 89;
	  section.data(38).dtTransOffset = 39;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_DW.sfEvent
	  section.data(1).logicalSrcIdx = 90;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Callibration_check_Robot_Ipos_DW.sfEvent_e
	  section.data(2).logicalSrcIdx = 91;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Callibration_check_Robot_Ipos_DW.sfEvent_l
	  section.data(3).logicalSrcIdx = 92;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Callibration_check_Robot_Ipos_DW.sfEvent_m
	  section.data(4).logicalSrcIdx = 93;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Callibration_check_Robot_Ipos_DW.sfEvent_o
	  section.data(5).logicalSrcIdx = 94;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_DW.is_c1_Callibration_check_Robot_
	  section.data(1).logicalSrcIdx = 95;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Callibration_check_Robot_Ipos_DW.is_c18_Callibration_check_Robot
	  section.data(2).logicalSrcIdx = 96;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Callibration_check_Robot_Ipos_DW.is_c16_Callibration_check_Robot
	  section.data(3).logicalSrcIdx = 97;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Callibration_check_Robot_Ipos_DW.is_c12_Callibration_check_Robot
	  section.data(4).logicalSrcIdx = 98;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Callibration_check_Robot_Ipos_DW.is_Object_Detection
	  section.data(5).logicalSrcIdx = 99;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Callibration_check_Robot_Ipos_DW.is_Belt
	  section.data(6).logicalSrcIdx = 100;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Callibration_check_Robot_Ipos_DW.is_Robot_Arm
	  section.data(7).logicalSrcIdx = 101;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Callibration_check_Robot_Ipos_DW.is_Vacuum
	  section.data(8).logicalSrcIdx = 102;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Callibration_check_Robot_Ipos_DW.NS
	  section.data(9).logicalSrcIdx = 103;
	  section.data(9).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_DW.NF
	  section.data(1).logicalSrcIdx = 104;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_DW.temporalCounter_i1
	  section.data(1).logicalSrcIdx = 105;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Callibration_check_Robot_Ipos_DW.temporalCounter_i1_b
	  section.data(2).logicalSrcIdx = 106;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Callibration_check_Robot_Ipos_DW.temporalCounter_i1_h
	  section.data(3).logicalSrcIdx = 107;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Callibration_check_Robot_Ipos_DW.temporalCounter_i1_p
	  section.data(4).logicalSrcIdx = 108;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_DW.Subsystem3_SubsysRanBC
	  section.data(1).logicalSrcIdx = 109;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Callibration_check_Robot_Ipos_DW.IfActionSubsystem1_SubsysRanBC
	  section.data(2).logicalSrcIdx = 110;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Callibration_check_Robot_Ipos_DW.IfActionSubsystem_SubsysRanBC
	  section.data(3).logicalSrcIdx = 111;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Callibration_check_Robot_Ipos_DW.Controller_SubsysRanBC
	  section.data(4).logicalSrcIdx = 112;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Callibration_check_Robot_Ipos_DW.EnabledSubsystem_SubsysRanBC
	  section.data(5).logicalSrcIdx = 113;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_DW.is_active_c1_Callibration_check
	  section.data(1).logicalSrcIdx = 114;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Callibration_check_Robot_Ipos_DW.is_active_c18_Callibration_chec
	  section.data(2).logicalSrcIdx = 115;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Callibration_check_Robot_Ipos_DW.is_active_c16_Callibration_chec
	  section.data(3).logicalSrcIdx = 116;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Callibration_check_Robot_Ipos_DW.is_active_c12_Callibration_chec
	  section.data(4).logicalSrcIdx = 117;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Callibration_check_Robot_Ipos_DW.is_active_c3_Callibration_check
	  section.data(5).logicalSrcIdx = 118;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Callibration_check_Robot_Ipos_DW.is_active_Object_Detection
	  section.data(6).logicalSrcIdx = 119;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Callibration_check_Robot_Ipos_DW.is_active_Belt
	  section.data(7).logicalSrcIdx = 120;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Callibration_check_Robot_Ipos_DW.is_active_Robot_Arm
	  section.data(8).logicalSrcIdx = 121;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Callibration_check_Robot_Ipos_DW.is_active_Vacuum
	  section.data(9).logicalSrcIdx = 122;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Callibration_check_Robot_Ipos_DW.busy
	  section.data(10).logicalSrcIdx = 123;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_DW.doneDoubleBufferReInit
	  section.data(1).logicalSrcIdx = 124;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Callibration_check_Robot_Ipos_DW.eml_autoflush
	  section.data(2).logicalSrcIdx = 125;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_DW.eml_openfiles
	  section.data(1).logicalSrcIdx = 126;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_DW.Controller_MODE
	  section.data(1).logicalSrcIdx = 127;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_DW.sf_MATLABFunction1.previous_value_reference_start
	  section.data(1).logicalSrcIdx = 128;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Callibration_check_Robot_Ipos_DW.sf_MATLABFunction1.previous_value_reference_end
	  section.data(2).logicalSrcIdx = 129;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Callibration_check_Robot_Ipos_DW.sf_MATLABFunction1.index
	  section.data(3).logicalSrcIdx = 130;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_DW.sf_MATLABFunction1.path_array
	  section.data(1).logicalSrcIdx = 131;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_DW.sf_MATLABFunction1.path_array_not_empty
	  section.data(1).logicalSrcIdx = 132;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_DW.sf_MATLABFunction.previous_value_reference_start
	  section.data(1).logicalSrcIdx = 133;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Callibration_check_Robot_Ipos_DW.sf_MATLABFunction.previous_value_reference_end
	  section.data(2).logicalSrcIdx = 134;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Callibration_check_Robot_Ipos_DW.sf_MATLABFunction.index
	  section.data(3).logicalSrcIdx = 135;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_DW.sf_MATLABFunction.path_array
	  section.data(1).logicalSrcIdx = 136;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_DW.sf_MATLABFunction.path_array_not_empty
	  section.data(1).logicalSrcIdx = 137;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(19) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_DW.sf_MATLABFunction2.previous_value_reference_start
	  section.data(1).logicalSrcIdx = 138;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Callibration_check_Robot_Ipos_DW.sf_MATLABFunction2.previous_value_reference_end
	  section.data(2).logicalSrcIdx = 139;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Callibration_check_Robot_Ipos_DW.sf_MATLABFunction2.index
	  section.data(3).logicalSrcIdx = 140;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(20) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_DW.sf_MATLABFunction2.path_array
	  section.data(1).logicalSrcIdx = 141;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(21) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_DW.sf_MATLABFunction2.path_array_not_empty
	  section.data(1).logicalSrcIdx = 142;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(22) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_DW.SerialWrite.obj
	  section.data(1).logicalSrcIdx = 143;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(23) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_DW.SerialWrite.objisempty
	  section.data(1).logicalSrcIdx = 144;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(24) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_DW.SerialWrite1.obj
	  section.data(1).logicalSrcIdx = 145;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(25) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Callibration_check_Robot_Ipos_DW.SerialWrite1.objisempty
	  section.data(1).logicalSrcIdx = 146;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(26) = section;
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


  targMap.checksum0 = 3532189429;
  targMap.checksum1 = 253923799;
  targMap.checksum2 = 274992694;
  targMap.checksum3 = 3710732855;

