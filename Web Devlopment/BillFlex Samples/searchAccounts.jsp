<!DOCTYPE html>
<%@ page language="java" pageEncoding="UTF-8"%>
<%@page import="com.alligato.util.ConfigFactory"%>
<%@page import="com.alligato.common.AppConstants"%>
<%@page import="com.alligato.util.AppHolder"%>
<%@ taglib prefix="s" uri="/struts-tags"%>
<%
	String path = request.getContextPath();
	ConfigFactory factory = ConfigFactory.getInstance(AppHolder
			.getContextPath());
%>

<!--[if lt IE 7]> <html class="no-js lt-ie9 lt-ie8 lt-ie7" lang="en"> <![endif]-->
<!--[if IE 7]>    <html class="no-js lt-ie9 lt-ie8" lang="en"> <![endif]-->
<!--[if IE 8]>    <html class="no-js lt-ie9" lang="en"> <![endif]-->
<html class="no-js" lang="en">
<head>

<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<title>Alligato Customer Care</title>

<!-- <link href="<s:url value="css/crm.css"/>" rel="stylesheet" type="text/css" /> -->
<link rel="stylesheet" href="${S_PATH }/css/foundation.css">
<link rel="stylesheet" href="${S_PATH }/css/app.css">
<link rel="stylesheet" href="${S_PATH }/css/jquery.dataTables.css">
<link rel="stylesheet" href="${S_PATH }/css/jquery.dataTables_themeroller.css">
<link rel="stylesheet" href="${S_PATH }/css/override.css">


<script type="text/javascript" src="js/swap_img.js"></script>
<script type="text/javascript" src="js/account/searchaccount.js"></script>
<script type="text/javascript" src="js/unicom7.js"></script>
<script type="text/javascript" src="js/alligato_utils.js"></script>
<!-- Dependencies -->

<script type="text/javascript">
var dataTable = null;
	function resetCriteria() {
		$("#params_id").val("");
		$("#params_accountName").val("");
		$("#params_serviceNumber").val("");
		$("#param_bill_cicle").prop('selectedIndex', 0);
		$("#param_bill_cicle").trigger('change');
		//$("select#param_bill_cicle").get(0).selectedIndex = 0;
		$("#params_address").val("");
		$("#params_postalCode").val("");
		$("#params_amount").val("");
		$("#params_amountMax").val("");

	}

	function ajaxSearchAccount() {
	var _id = $('#params_id').val();
		var _accountName = $('#params_accountName').val();
		var _serviceNumber = $('#params_serviceNumber').val();
		var _billCicle = $('#param_bill_cicle').val();
		var _address = $('#params_address').val();
		var _postalCode = $('#params_postalCode').val();
		if (isEmpty(_id) && isEmpty(_accountName) && isEmpty(_serviceNumber)
				&& isEmpty(_billCicle) && isEmpty(_address)
				&& isEmpty(_postalCode) /*&& isEmpty(_amount) && isEmpty(_amountMax)*/) {
			alert("Please specify a search criteria.");
			return false;
		}
		
		$('#example').css('display', '');

		var params = '${S_PATH}/list/listAccounts.action?params.accountNumber='
				+ _id + '&params.accountName=' + _accountName
				+ '&params.serviceNumber=' + _serviceNumber
				+ '&params.billingCycle=' + _billCicle + '&params.address1='
				+ _address + '&params.postalCode=' + _postalCode /*+ '&params.amount=' + _amount + '&params.amountMax=' + _amountMax*/;

	if(dataTable == null){
		dataTable = $('#example').dataTable( {
						"bProcessing": true,
						"sAjaxSource": params,
						"sAjaxDataProp": "accounts",
						"sPaginationType": "full_numbers",
						"bAutoWidth":false,
						"aoColumns": [

							{"sDefaultContent": "n/a"},
							{ "mData": "accountNumber" },
							{ "mData": "accountName" },
							{ "mData": "homeTelephone" },
							{ "mData": "billingCycle" },
							{ "mData": "status" }
						],
						"fnRowCallback": function( nRow, aData, iDisplayIndex ) {
							$('td:eq(1)', nRow).html( "<a href=\"javascript:showModal('${S_PATH}/editAccount.action?account.accountNumber="+ 
														aData.accountNumber
														+ "','','dialogHeight:800px;dialogWidth:1530px;resizable:yes;edge:raised;modal:yes')\">" + 
														aData.accountNumber +
														"</a>");
							$('td:eq(0)',nRow).html("<input class='input_check' type='checkbox' name='previewValues' value='"
									+ aData.accountNumber + "'/>");
							$('td:eq(5)', nRow).html(getAccountStatus(aData.status));
							aData.status = getAccountStatus(aData.status);
							return nRow;
						}
					} );
	}else{
		dataTable.fnDestroy();
		dataTable = $('#example').dataTable( {
						"bProcessing": true,
						"sAjaxSource": params,
						"sAjaxDataProp": "accounts",
						"sPaginationType": "full_numbers",
						"bAutoWidth":false,
						"aoColumns": [
							{"sDefaultContent": "n/a"},
							{ "mData": "accountNumber" },
							{ "mData": "accountName" },
							{ "mData": "homeTelephone" },
							{ "mData": "billingCycle" },
							{ "mData": "status" }
						],
						"fnRowCallback": function( nRow, aData, iDisplayIndex ) {
							$('td:eq(1)', nRow).html( "<a href=\"javascript:showModal('${S_PATH}/editAccount.action?account.accountNumber="+ 
														aData.accountNumber
														+ "','','dialogHeight:800px;dialogWidth:1530px;resizable:yes;edge:raised;modal:yes')\">" + 
														aData.accountNumber +
														"</a>");
							$('td:eq(0)',nRow).html("<input class='input_check' type='checkbox' name='previewValues' value='"
									+ aData.accountNumber + "'/>");
							$('td:eq(5)', nRow).html(getAccountStatus(aData.status));
							return nRow;
						}
					} );
	}
	
}
	function clearTable(){
		if(dataTable != null){
			dataTable.fnClearTable();
		}
	}
	
	function ajaxSearcAccountBkp() {
		var _id = YAHOO.util.Dom.get("params_id").value;
		var _accountName = YAHOO.util.Dom.get("params_accountName").value;
		var _serviceNumber = YAHOO.util.Dom.get("params_serviceNumber").value;
		var _billCicle = YAHOO.util.Dom.get("param_bill_cicle").value;
		var _address = YAHOO.util.Dom.get("params_address").value;
		var _postalCode = YAHOO.util.Dom.get("params_postalCode").value;
		/* var _amount = YAHOO.util.Dom.get("params_amount").value;
		 var _amountMax = YAHOO.util.Dom.get("params_amountMax").value;
		 */
		if (isEmpty(_id) && isEmpty(_accountName) && isEmpty(_serviceNumber)
				&& isEmpty(_billCicle) && isEmpty(_address)
				&& isEmpty(_postalCode) /*&& isEmpty(_amount) && isEmpty(_amountMax)*/) {
			alert("Please specify a search criteria.");
			return false;
		}

		if (!isEmpty(_id) && !_id.match("^[0-9]*$")) {
			alert("Account id must be numeric.");
			YAHOO.util.Dom.get("params_id").value = '';
			YAHOO.util.Dom.get("params_id").focus();
			return false;
		}
		/* if (!isEmpty(_amount) && !_amount.match("^[0-9]*$")){
		 alert("Min Payment Due must be numeric.");
		 YAHOO.util.Dom.get("params_amount").value = '';
		 YAHOO.util.Dom.get("params_amount").focus();
		 return false;
		 }*/
		/* if (!isEmpty(_amountMax) && !_amountMax.match("^[0-9]*$")){
		 alert("Max Payment Due must be numeric.");
		 YAHOO.util.Dom.get("params_amountMax").value = '';
		 YAHOO.util.Dom.get("params_amountMax").focus();
		 return false;
		 }*/
		/* if (!isEmpty(_amount) && !isEmpty(_amountMax)){
		 if(_amount > _amountMax){
		 alert("Invalid Payment due range.");
		 return false;
		 }
		 } 	*/
		var params = '${S_PATH}/list/listAccounts.action?params.accountNumber='
				+ _id + '&params.accountName=' + _accountName
				+ '&params.serviceNumber=' + _serviceNumber
				+ '&params.billingCycle=' + _billCicle + '&params.address1='
				+ _address + '&params.postalCode=' + _postalCode /*+ '&params.amount=' + _amount + '&params.amountMax=' + _amountMax*/;

		this.formatUrl = function(elCell, oRecord, oColumn, sData) {
			elCell.innerHTML = "<a href=\"javascript:showModal('${S_PATH}/editAccount.action?account.accountNumber="
					+ oRecord.getData("accountNumber")
					+ "','','dialogHeight:800px;dialogWidth:1530px;resizable:no;edge:raised;modal:yes')\">"
					+ sData + "</a>";
		};

		this.formatCheckBox = function(elCell, oRecord, oColumn, sData) {
			elCell.innerHTML = "<input class='input_check' type='checkbox' name='previewValues' value='"
					+ oRecord.getData("accountNumber") + "'/>";
		};

		this.formatStatus = function(elCell, oRecord, oColumn, sData) {
			elCell.innerHTML = getAccountStatus(sData);
		};
		var myColumnDefs = [ {
			label : " ",
			formatter : this.formatCheckBox,
			width : "5%"
		}, {
			label : "Account No",
			key : "accountNumber",
			formatter : this.formatUrl,
			sortable : true,
			width : "15%"
		}, {
			label : "Account Name",
			key : "accountName",
			sortable : true,
			width : "40%"
		}, {
			label : "Telephone",
			key : "homeTelephone",
			sortable : true,
			width : "10%"
		}, {
			label : "Billing Cycle Code",
			key : "billingCycle",
			sortable : true,
			width : "15%"
		}, {
			label : "Account Status",
			key : "status",
			formatter : this.formatStatus,
			sortable : true,
			width : "15%"
		} ];

		this.myDataSource = new YAHOO.util.DataSource(params);
		this.myDataSource.responseType = YAHOO.util.DataSource.TYPE_JSON;
		this.myDataSource.responseSchema = {
			resultsList : "accounts",
			fields : [ "accountNumber", "accountName", "homeTelephone",
					"billingCycle", "status" ]
		};

		var oConfigs = {
			paginated : true,
			paginator : {
				rowsPerPage : 25,
				dropdownOptions : [ 25, 50, 100 ]
			}
		};

		this.myDataTable = new YAHOO.widget.DataTable("mainSearchContainer",
				myColumnDefs, this.myDataSource, oConfigs);
		this.myDataTable
				.subscribe(
						"initEvent",
						function(oArgs) {//debugger;   
							if (this._oRecordSet.getLength() == 0) {
								document.getElementById("preview_btn").style.visibility = 'hidden';
							} else {
								document.getElementById("preview_btn").style.visibility = '';
							}
						});
	};

	function isEmpty(value) {
		var error = false;
		if (value != null
				&& (value == "" || value.replace(/^\s+|\s+$/g, "").length == 0)) {
			error = true;
		}
		return error;
	}
</script>


<script src="${S_PATH }/js/modernizr.foundation.js"></script>
</head>

<body class="yui-skin-sam"
	onload="MM_preloadImages('img/escalations_m.gif','img/close_m.gif','img/save_m.gif','img/preview_m.gif','img/new_m.gif','img/open_m.gif','img/history_m.gif','img/export_m.gif','img/import_m.gif','img/find_m.gif');document.getElementById('params_id').focus();$('#mainContainer').show();">
	<jsp:include page="/inc/menu.jsp" />
	<div class="container">

		<ul class="breadcrumbs">
			<li><a href="${S_PATH }">Main Menu</a></li>
			<li class="current"><a href="#">Customer Care</a></li>
		</ul>
	</div>
	<div class="header">
	<s:form cssClass="custom" theme="simple" method="post"
		action="searchAccounts">
		<div class="large-12 columns">
		<div class="panel all-corners main-menu-title">
				<h5>Customer Care</h5>
			</div>
			<fieldset id="mainContainer" class="main_wrapper">
				<legend>Search Criteria</legend>
				<!--row1_ms starts-->
				<div class="row_data clear">
					<div class="dataField">
						<label for="params_id" class="custom-label">Account No</label>
						<s:textfield cssClass="input_size" name="params.accountNumber"
							id="params_id" onkeyup="enterSubmit(event,'ajaxSearcAccount')" />
					</div>
					<div class="dataField">
						<label for="params_accountName" class="custom-label">Account Name</label>
						<s:textfield cssClass="input_size" name="params.accountName"
							id="params_accountName"
							onkeyup="enterSubmit(event,'ajaxSearcAccount')" />
					</div>
					<div class="dataField">
						<label for="params_serviceNumber" class="custom-label">Service Number</label>
						<s:textfield cssClass="input_size" name="params.serviceNumber"
							id="params_serviceNumber"
							onkeyup="enterSubmit(event,'ajaxSearcAccount')" />
					</div>
					<div class="dataField smaller-select">
						<label for="param_bill_cicle" class="custom-label">Bill Cycle</label>
						<s:select cssClass="input_size" name="params.billingCycle" emptyOption="true"
							id="param_bill_cicle" list="#session.iGetBillingCycles"
							listKey="code" listValue="description"  />
					</div>
					<div class="dataField">
						<label for="params_address" class="custom-label">Address</label>
						<s:textfield cssClass="input_size" name="params.address1"
							id="params_address"
							onkeyup="enterSubmit(event,'ajaxSearcAccount')" />
					</div>
					<div class="dataField">
						<label for="params_postalCode" class="custom-label">Postal Code</label>
						<s:textfield cssClass="input_size" name="params.postalCode" 
							id="params_postalCode"
							onkeyup="enterSubmit(event,'ajaxSearcAccount')" />
					</div>
				</div>
				<div class="clear"></div>
			<div class="actions-1">
			<ul class="inline-block">
					<li><input type="reset" id="clear" name="clear" class="secondary button radius" onclick="resetCriteria();clearTable()" value="Clear Fields" title="Clear All Info Fields?" /></li>
					<li><input type="button" id="search" name="clear" class="button radius" onclick="showTable()" value="Search" title="Search" /></li>
			</ul>
			</div>
			<div class="clear"></div>
				
				
			</fieldset>
		</div>
	</s:form>
	</div>
	<div class="main_wrapper" id="mainSearchContainer"></div>
	<div id="dynamic" style="width: 97%; margin: auto;">
		<table id="example" class="display" style="display:none;">
			<thead>
				<tr>
					<th width="5%"></th>
					<th width="25%">Account No</th>
					<th width="25%">Account Name</th>
					<th width="25%">Telephone</th>
					<th width="10%">Billing Cycle</th>
					<th width="10%">Account Status</th>
				</tr>
			</thead>
			<tbody>
				<tr>
					<td colspan="5" class="dataTables_empty"></td>
				</tr>
			</tbody>
		</table>
	</div>
	<div class="main_wrapper">
		<div id="btn_l">
			<a id="preview_btn" href="#" style="visibility: hidden"
				onmouseout="MM_swapImgRestore()"
				onmouseover="MM_swapImage('Preview','','img/preview_m.gif',1)">
				<img src="img/preview.gif" alt="Preview" name="Preview" width="116"
				height="20" border="0" id="Preview" onclick="submitAccountPreview()" />
			</a>
		</div>

	</div>

	<!-- Included JS Files (Compressed) -->
	<script src="${S_PATH }/js/foundation.min.js"></script>
	<script type="text/javascript" src="js/jquery.dataTables.min.js"></script>

	<!-- Initialize JS Plugins -->
	<script src="${S_PATH }/js/app.js"></script>
	
	<script type="text/javascript">

		function showTable()
		{
			ajaxSearchAccount();
		}
	</script>
</body>
</html>