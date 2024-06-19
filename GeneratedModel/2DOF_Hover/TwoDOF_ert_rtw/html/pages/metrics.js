function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["TwoDOF.c:TwoDOF_M_"] = {file: "F:\\College\\Semester_10\\GP2\\2DOF\\2DOF_Hover\\GeneratedModel\\2DOF_Hover\\TwoDOF_ert_rtw\\TwoDOF.c",
	size: 8};
	 this.metricsArray.var["TwoDOF_DW"] = {file: "F:\\College\\Semester_10\\GP2\\2DOF\\2DOF_Hover\\GeneratedModel\\2DOF_Hover\\TwoDOF_ert_rtw\\TwoDOF.c",
	size: 288};
	 this.metricsArray.var["TwoDOF_U"] = {file: "F:\\College\\Semester_10\\GP2\\2DOF\\2DOF_Hover\\GeneratedModel\\2DOF_Hover\\TwoDOF_ert_rtw\\TwoDOF.c",
	size: 16};
	 this.metricsArray.var["TwoDOF_Y"] = {file: "F:\\College\\Semester_10\\GP2\\2DOF\\2DOF_Hover\\GeneratedModel\\2DOF_Hover\\TwoDOF_ert_rtw\\TwoDOF.c",
	size: 64};
	 this.metricsArray.fcn["TwoDOF_initialize"] = {file: "F:\\College\\Semester_10\\GP2\\2DOF\\2DOF_Hover\\GeneratedModel\\2DOF_Hover\\TwoDOF_ert_rtw\\TwoDOF.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["TwoDOF_step"] = {file: "F:\\College\\Semester_10\\GP2\\2DOF\\2DOF_Hover\\GeneratedModel\\2DOF_Hover\\TwoDOF_ert_rtw\\TwoDOF.c",
	stack: 159,
	stackTotal: 159};
	 this.metricsArray.fcn["TwoDOF_terminate"] = {file: "F:\\College\\Semester_10\\GP2\\2DOF\\2DOF_Hover\\GeneratedModel\\2DOF_Hover\\TwoDOF_ert_rtw\\TwoDOF.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["cos"] = {file: "F:\\00_Programs\\MATLAB\\R2023b\\polyspace\\verifier\\cxx\\include\\include-libc\\bits\\mathcalls.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["sin"] = {file: "F:\\00_Programs\\MATLAB\\R2023b\\polyspace\\verifier\\cxx\\include\\include-libc\\bits\\mathcalls.h",
	stack: 0,
	stackTotal: 0};
	 this.getMetrics = function(token) { 
		 var data;
		 data = this.metricsArray.var[token];
		 if (!data) {
			 data = this.metricsArray.fcn[token];
			 if (data) data.type = "fcn";
		 } else { 
			 data.type = "var";
		 }
	 return data; }; 
	 this.codeMetricsSummary = '<a href="javascript:void(0)" onclick="return postParentWindowMessage({message:\'gotoReportPage\', pageName:\'TwoDOF_metrics\'});">Global Memory: 376(bytes) Maximum Stack: 159(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
