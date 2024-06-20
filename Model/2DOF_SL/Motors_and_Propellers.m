classdef Motors_and_Propellers < matlab.System ...
        & coder.ExternalDependency ...
        & matlabshared.sensors.simulink.internal.BlockSampleTime

    % Gives operating point to motors connected to ESCs
    %#codegen
    %#ok<*EMCA>

    properties

    end

    properties(Access = protected)
        Logo = 'IO Device Builder';
    end

    properties (Nontunable)

    end

    properties (Access = private)


    end

    methods
        % Constructor
        function obj = Motors_and_Propellers(varargin)
            setProperties(obj,nargin,varargin{:});
        end
    end

    methods (Access=protected)
        function setupImpl(obj)
            if ~coder.target('MATLAB')
                coder.cinclude('Motors_and_Propellers.h');
                coder.ceval('setupFunctionMotors_and_Propellers');
            end
        end

        function validateInputsImpl(obj,varargin)
            %  Check the input size
            if nargin ~=0

                validateattributes(varargin{1},{'double'},{'2d','size',[1,1]},'','Xaction');
                validateattributes(varargin{2},{'double'},{'2d','size',[1,1]},'','Yaction');

            end
        end

        function stepImpl(obj ,Xaction,Yaction)

            if isempty(coder.target)
            else
                coder.ceval('stepFunctionMotors_and_Propellers', Xaction,1, Yaction,1);
            end
        end

        function releaseImpl(obj)
            if isempty(coder.target)
            else

            end
        end
    end

    methods (Access=protected)
        %% Define output properties
        function num = getNumInputsImpl(~)
            num = 2;
        end

        function num = getNumOutputsImpl(~)
            num = 0;
        end

        function varargout = getInputNamesImpl(obj)
            varargout{1} = 'Xaction';
            varargout{2} = 'Yaction';

        end

        function varargout = getOutputNamesImpl(obj)

        end

        function flag = isOutputSizeLockedImpl(~,~)
            flag = true;
        end

        function varargout = isOutputFixedSizeImpl(~,~)

        end

        function varargout = isOutputComplexImpl(~)

        end

        function varargout = getOutputSizeImpl(~)

        end

        function varargout = getOutputDataTypeImpl(~)

        end

        function maskDisplayCmds = getMaskDisplayImpl(obj)
            outport_label = [];
            num = getNumOutputsImpl(obj);
            if num > 0
                outputs = cell(1,num);
                [outputs{1:num}] = getOutputNamesImpl(obj);
                for i = 1:num
                    outport_label = [outport_label 'port_label(''output'',' num2str(i) ',''' outputs{i} ''');' ]; %#ok<AGROW>
                end
            end
            inport_label = [];
            num = getNumInputsImpl(obj);
            if num > 0
                inputs = cell(1,num);
                [inputs{1:num}] = getInputNamesImpl(obj);
                for i = 1:num
                    inport_label = [inport_label 'port_label(''input'',' num2str(i) ',''' inputs{i} ''');' ]; %#ok<AGROW>
                end
            end
            icon = 'Motors_and_Propellers';
            maskDisplayCmds = [ ...
                ['color(''white'');',...
                'plot([100,100,100,100]*1,[100,100,100,100]*1);',...
                'plot([100,100,100,100]*0,[100,100,100,100]*0);',...
                'color(''blue'');', ...
                ['text(38, 92, ','''',obj.Logo,'''',',''horizontalAlignment'', ''right'');',newline],...
                'color(''black'');'], ...
                ['text(52,50,' [''' ' icon ''',''horizontalAlignment'',''center'');' newline]]   ...
                inport_label ...
                outport_label
                ];
        end

        function sts = getSampleTimeImpl(obj)
            sts = getSampleTimeImpl@matlabshared.sensors.simulink.internal.BlockSampleTime(obj);
        end
    end

    methods (Static, Access=protected)
        function simMode = getSimulateUsingImpl(~)
            simMode = 'Interpreted execution';
        end

        function isVisible = showSimulateUsingImpl
            isVisible = false;
        end
    end

    methods (Static)
        function name = getDescriptiveName()
            name = 'Motors_and_Propellers';
        end

        function b = isSupportedContext(context)
            b = context.isCodeGenTarget('rtw');
        end

        function updateBuildInfo(buildInfo, context)
            coder.extrinsic('matlabshared.sensors.simulink.internal.getTargetHardwareName');
            targetname = coder.const(matlabshared.sensors.simulink.internal.getTargetHardwareName);
            % Get the filelocation of the SPKG specific files
            coder.extrinsic('matlabshared.sensors.simulink.internal.getTargetSpecificFileLocationForSensors');
            fileLocation = coder.const(@matlabshared.sensors.simulink.internal.getTargetSpecificFileLocationForSensors,targetname);
            coder.extrinsic('which');
            coder.extrinsic('error');
            coder.extrinsic('message');
            funcName = [fileLocation,'.getTargetSensorUtilities'];
            functionPath = coder.const(@which,funcName);
            % Only if the the path exist
            if ~isempty(fileLocation)
                % internal error to see if the target author has provided
                % the expected function in the specified file location
                assert(~isempty(functionPath),message('matlab_sensors:general:FunctionNotAvailableSimulinkSensors','getTargetSensorUtilities'));
                funcHandle = str2func(funcName);
                hwUtilityObject = funcHandle('I2C');
                assert(isa(hwUtilityObject,'matlabshared.sensors.simulink.internal.SensorSimulinkBase'),message('matlab_sensors:general:invalidHwObjSensorSimulink'));
            else
                hwUtilityObject = '';
            end

            if ~isempty(hwUtilityObject)
                hwUtilityObject.updateBuildInfo(buildInfo, context);
            end

            % buildInfo.addIncludePaths('F:\College\Semester_10\GP2\2DOF\2DOF_Hover\Model\2DOF_SL\SourceFiles\Motors');
            buildInfo.addIncludePaths(pwd+'\SourceFiles\Motors');

            % buildInfo.addIncludePaths('F:\College\Semester_10\GP2\2DOF\2DOF_Hover\Model\2DOF_SL');
            buildInfo.addIncludePaths(pwd);
            
            % addSourceFiles(buildInfo,'Motors.cpp','F:\College\Semester_10\GP2\2DOF\2DOF_Hover\Model\2DOF_SL\SourceFiles\Motors');
            % addSourceFiles(buildInfo,'Motors_and_Propellers.cpp','F:\College\Semester_10\GP2\2DOF\2DOF_Hover\Model\2DOF_SL');
            addSourceFiles(buildInfo,'Motors.cpp',pwd+'\SourceFiles\Motors');
            addSourceFiles(buildInfo,'ESP32Servo.cpp',pwd+'\SourceFiles\Motors');
            addSourceFiles(buildInfo,'Motors_and_Propellers.cpp',pwd);
        end
    end
end
