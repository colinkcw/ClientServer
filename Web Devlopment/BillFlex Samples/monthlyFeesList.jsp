<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<%@ page language="java" pageEncoding="UTF-8"
	contentType="text/html;charset=UTF-8"%>
<%@page import="com.alligato.action.ordermgmt.OrderMgmtConstants"%>
<%@ taglib prefix="s" uri="/struts-tags"%>
<%
	String path = request.getContextPath();
%>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<title>Alligato Customer Care - Monthly Billing Fees</title>


<link rel="stylesheet" href="${S_PATH }/css/foundation.css">
<link rel="stylesheet" href="${S_PATH }/css/app.css">
<link rel="stylesheet" href="${S_PATH }/css/jquery.dataTables.css">
<link rel="stylesheet" href="${S_PATH }/css/jquery.dataTables_themeroller.css">


<!-- <link href="<s:url value="/css/common.css"/>" rel="stylesheet" type="text/css" />
<link href="<s:url value="/css/crm.css"/>" rel="stylesheet" type="text/css" /> -->

<link rel="stylesheet" href="${S_PATH }/css/override.css">
<!--CSS file (default YUI Sam Skin) -->
<link type="text/css" rel="stylesheet" href="<%=path%>/struts/yui/build/datatable/assets/skins/sam/datatable-skin.css" />
<script type="text/javascript" language="javascript" src="<%=path%>/js/swap_img.js"></script>
<script type="text/javascript" language="javascript" src="<%=path%>/js/unicom7.js"></script>
<script type="text/javascript" language="javascript" src="<%=path%>/js/billing.js"></script>
<script type="text/javascript" language="javascript" src="<%=path%>/js/alligato_utils.js"></script>

<script type="text/javascript" src="${S_PATH }/js/foundation.min.js"></script>
<script type="text/javascript"
	src="${S_PATH }/js/jquery.dataTables.min.js"></script>

<script type="text/javascript">
//     function disableEnableButtons(){
//      var accStatus = window.frameElement.ownerDocument.getElementById('account_status_id');  
//      var addBtn = document.getElementById('Add'); 
//      if(accStatus.value == "Terminated") {
//        addBtn.setAttribute("onclick","");
//      }  
//     }
      
	  var listed=false;
	  function showItem(x,y){
          var editUrl = "<%=path%>/editAccountMonthlyFees.action?monthlyFees.accountNumber=";
          editUrl = editUrl + '<s:text  name="%{monthlyFees.accountNumber}" />';
          editUrl = editUrl + '&name=' + escape($("#name").val());
          editUrl = editUrl + '&firstName=' + escape($("#firstName").val());
          editUrl = editUrl + '&lastName=' + escape($("#lastName").val());
          editUrl = editUrl + '&companyName=' + escape($("#companyName").val());
          editUrl = editUrl + '&accountStatus=' + '<s:text name="%{accountStatus}" />';
          editUrl = editUrl + '&startDate=' + document.getElementById("startDate").value;
          editUrl = editUrl + "&monthlyFees.monthlyFeeId="+ x +'*'+ y;
		showModal(editUrl, window, 'dialogHeight:610px;dialogWidth:1015px;toolbar:no;directories:no;status:no;menubar:no;scrollbars:no;resizable:no;modal:yes');
	  }
	  function showItembk(x,y){
          var editUrl = "<%=path%>/editAccountMonthlyFees.action?monthlyFees.accountNumber=";
          editUrl = editUrl + '<s:text  name="%{monthlyFees.accountNumber}" />';
          editUrl = editUrl + '&name=' + escape($yd.get("name").value);
          editUrl = editUrl + '&firstName=' + escape($yd.get("firstName").value);
          editUrl = editUrl + '&lastName=' + escape($yd.get("lastName").value);
          editUrl = editUrl + '&companyName=' + escape($yd.get("companyName").value);
          editUrl = editUrl + '&accountStatus=' + '<s:text name="%{accountStatus}" />';
          editUrl = editUrl + '&startDate=' + document.getElementById("startDate").value;
          editUrl = editUrl + "&monthlyFees.monthlyFeeId="+ x +'*'+ y;
		showModal(editUrl, window, 'dialogHeight:610px;dialogWidth:1015px;toolbar:no;directories:no;status:no;menubar:no;scrollbars:no;resizable:no;modal:yes');
	  }
	  var dataTable = null; 
	  function listMonthlyBillingFees(){
	  	var queryString = '<%=path%>/list/listAccountMonthlyFees.action?monthlyFees.accountNumber=<s:text name="%{monthlyFees.accountNumber}"/>';
	  	dataTable = $('#monthlyFeesTable').dataTable( {
			"bProcessing": true,
			"sAjaxSource":queryString ,
			"bPaginate": true,
			"sAjaxDataProp": "mbfList",
			"bDestroy": true,
			"iDisplayLength":5,
			"bLengthChange": false,
			"sPaginationType": "full_numbers",
			'bAutoWidth': false,
			"aoColumns": [          
				{ "mData": "monthlyFeeCode" },
				{ "mData": "sequence" },
				{ "mData": "description" },
				{ "mData": "serviceNumber" },
				{ "mData": "status" },
				{ "mData": "quantity" },
				{ "mData": "unitPrice" }
			],
			"fnRowCallback": function( nRow, aData, iDisplayIndex ) {
					$('td:eq(0)', nRow).html("<a href=\"javascript:showItem('" + aData.monthlyFeeCode +"','"+ aData.sequence + "') \">" + aData.monthlyFeeCode + "</a>");
					
					$('td:eq(4)', nRow).html(getStatusDescription(aData.status));
									
			},
			"fnInitComplete": function() {
			    dataTable.fnAdjustColumnSizing();
			}


		});


	  } 
      function listMonthlyBillingFeesbk(tag) 
      {
        if(tag==true){
			if(listed){
				return true;
			}else{
				listed=true;
			}
		}
        var queryString = '<%=path%>/list/listAccountMonthlyFees.action?monthlyFees.accountNumber=<s:text name="%{monthlyFees.accountNumber}"/>';
        this.formatUrl = function(elCell, oRecord, oColumn, sData) {   
          elCell.innerHTML = "<a href=\"javascript:showItem('" + oRecord.getData("monthlyFeeCode") +"','"+ oRecord.getData("sequence") + "') \">" + sData + "</a>";
          };  
        this.formatCheckBox = function(elCell, oRecord, oColumn, sData) {  
          elCell.innerHTML = "<input class='input_check' type='checkbox' name='otgChk' value='" + oRecord.getData("serviceNumber") + "'/>"; 
          };
        this.formatStatus = function(elCell, oRecord, oColumn, sData) {
			elCell.innerHTML = getStatusDescription(sData);
		};
        var myColumnDefs = [
          //{label:" ", key:"id", formatter:this.formatCheckBox, width:40},
          {label:"Monthly Fee Code", key:"monthlyFeeCode", formatter:this.formatUrl, sortable:true},
          {label:"Sequence", key:"sequence", sortable:true},
          {label:"Description", key:"description", sortable:true},
          {label:"Service Number", key:"serviceNumber", sortable:true},
          {label:"Status", key:"status", formatter:this.formatStatus, sortable:true},
          {label:"Qty", key:"quantity", sortable:true},
          {label:"Unit Price", key:"unitPrice", sortable:true}
        ];
        this.myDataSource = new YAHOO.util.DataSource(queryString);
        this.myDataSource.responseType = YAHOO.util.DataSource.TYPE_JSON;
        this.myDataSource.responseSchema = {
          resultsList: "mbfList",  
          fields: ["monthlyFeeCode","sequence","description","serviceNumber","status","quantity","unitPrice"]
        };
        
        var oConfigs = {   
                 paginated:true,   
                 paginator: {   
                   rowsPerPage: 5, 
                   dropdownOptions: [5, 10]   
                 }, 
                 sortedBy:{key:"monthlyFeeCode",dir:"asc"} 
         };   
        this.myDataTable = new YAHOO.widget.DataTable("tableContainer",
              myColumnDefs, this.myDataSource, oConfigs);
        this.myDataTable.subscribe("initEvent", function(oArgs){//debugger;   
                     if(this._oRecordSet.getLength() > 0) {
                       document.getElementById("preview").attachEvent ('onclick', submitPreview);
                     } else {
                       document.getElementById("preview").detachEvent ('onclick', submitPreview);
                     } 
                 });               
      };
    </script>
<style>
#btn_l {
	width: 50%;
	float: left;
	display: inline;
}

#btn_r {
	width: 49%;
	float: left;
	text-align: right;
}
</style>
</head>

<body class="yui-skin-sam"
	onload="MM_preloadImages('<%=path%>/img/add_m.gif', '<%=path%>/img/preview_m.gif');listMonthlyBillingFees()">
	<div id="dynamic">
		<table id="monthlyFeesTable">
			<thead>
				<tr>

					<th width="20%">Monthly Fee Code</th>
					<th width="10%">Sequence</th>
					<th width="30%">Description</th>
					<th width="15%">Service Number</th>
					<th width="10%">Status</th>
					<th width="5%">Qty</th>
					<th width="10%">Unit Price</th>
				</tr>
			</thead>
			<tbody>
				<tr>
					<td colspan="5" class="dataTables_empty"></td>
				</tr>
			</tbody>
		</table>
	</div>
	<div class="clear"></div>
	<s:form theme="simple" action="accountMonthlyFeesList" target="_self">
	<div class="actions-1">
		<s:hidden id="monthlyFees.accountNumber"
			name="monthlyFees.accountNumber" />
		<s:hidden id="name" name="name" />
		<s:hidden id="firstName" name="firstName" />
		<s:hidden id="lastName" name="lastName" />
		<s:hidden id="companyName" name="companyName" />
		<s:hidden id="accountStatus" name="accountStatus" />
		<s:date name="startDate" format="MM/dd/yyyy" id="start_date" />
		<s:hidden id="startDate" name="startDate" value="%{start_date}" />
		<div class="clear"></div>
			<ul class="inline-block">
				<li><input type="button" id="refreshButton" name="refresh" class="secondary button radius small" onclick="listMonthlyBillingFees()" value="Refresh" />
				<!--        <a href="#" onmouseout="MM_swapImgRestore()" onmouseover="MM_swapImage('Preview','','<%=path%>/img/preview_m.gif',1)">-->
			<!--          <img src="<%=path%>/img/preview.gif" alt="Preview" name="Preview" width="116" height="20" border="0" id="Preview"/>-->
			<!--        </a>  -->
			</li>
				<li><s:if test="accountStatus == \"A\"">
			<input type="button" id="Add" name="Add" class="button radius small third-button-spacer" onclick="javascript:showModal(addUrl, 'UNICOM7_Account_MBF', 'dialogHeight:610px;dialogWidth:1015px;toolbar:no;directories:no;status:no;menubar:no;scrollbars:no;resizable:no;edge:sunken;modal:yes')" value="Add" />
			<div>
				<script>
					var addUrl = "<%=path%>/addAccountMonthlyFees.action?monthlyFees.accountNumber=";
					addUrl = addUrl + '<s:text  name="%{monthlyFees.accountNumber}" />';
					addUrl = addUrl + '&name=' + escape($("#name").val());
					  addUrl = addUrl + '&firstName=' + escape($("#firstName").val());
					  addUrl = addUrl + '&lastName=' + escape($("#lastName").val());
					  addUrl = addUrl + '&companyName='+ escape($("#companyName").val());
					addUrl = addUrl + '&accountStatus=<s:text  name="%{accountStatus}" />';
					addUrl = addUrl + '&startDate=' + '<s:text name="%{start_date}" />';
					addUrl = addUrl + '&processType=' + '<%=OrderMgmtConstants.PT_ADD_MBF%>';
					//addUrl = addUrl + "&accountName=" +window.frameElement.ownerDocument.getElementById("accountName").value;
				</script>
			</div>
		</s:if>
				</li>
			</ul>
			
			
	
		
		</div>
	</s:form>
	<hr>

</body>
</html>