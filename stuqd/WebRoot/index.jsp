<%@ page language="java" import="java.util.*"  contentType="text/html;charset=gb2312" %>
<%@ include file="iframe/head.jsp" %> 
<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@3.3.7/dist/css/bootstrap.min.css" integrity="sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u" crossorigin="anonymous">
<script type="text/javascript">
<!--
function reload(){
	document.getElementById("image").src="<%=request.getContextPath() %>/imageServlet?date="+new Date().getTime();
	$("#checkcode").val("");   // ����֤�����
} 
function verificationcode(){
 var text=$.trim($("#checkcode").val());
 $.post("${pageContext.request.contextPath}/verificationServlet",{op:text},function(data){
	 data=parseInt($.trim(data));
	 if(data>0){
		 $("#checklable").text("��֤����ȷ!").css("color","green");
	 }else{
		 $("#checklable").text("��֤�����!").css("color","red");
 			$("#checkcode").val(""); // ����֤�����
		    reload();  //��֤ʧ�ܺ���Ҫ������֤��
	 }
 });
}
//-->
</script>
<div class="main" style="">
 <div class="narea"><div>
</div></div>
<div class="rmain">        
<div class="tom"><div class="totitle"><span> </span></div></div>  
<div class="rlist">  
<FORM name="loginform" method="post" action="<%=basePath %>AdminServlet?method=one"> 
   <table width="100%" border="0" align="center" cellpadding="4" cellspacing="0" class="table">
	  <tbody>
	     <tr class="tr1">
            <td class="rldatee daslist"></td>
			<td class="rltitle daslist">&nbsp;&nbsp;&nbsp;&nbsp;��¼����</td> 
         </tr>
	     <tr class="tr1">
			<td class="rldatee daslist">��¼�ʺţ�</td> 
            <td class="rltitle dotlist"><input type="text" size="30" name="username" class="form-control" required /></td> 
         </tr> 
         <tr class="tr1">
			<td class="rldatee daslist">��¼���룺</td>
            <td class="rltitle dotlist"><input type="password" size="30" class="form-control" name="password" required /></td> 
         </tr>
         <tr class="tr1">
			<td class="rldatee daslist">��֤�룺</td>
            <td class="rltitle dotlist">
            <input type="text" size="30" name="checkcode" id="checkcode"  class="form-control" onblur="javascript:verificationcode()" required />
            <label id="checklable"></label>
<br />
<img src="<%=request.getContextPath()%>/imageServlet" alt="��֤��" id="image" />
<a href="javascript:reload();"><label>��һ��</label>
</a>
<br>
            </td> 
         </tr>
         <tr class="tr1">
			<td class="rldatee daslist">��ݣ�</td>
            <td class="rltitle dotlist">
            <label><input type="radio" name="sf" value="����Ա" checked="checked"> ����Ա</label>
             </td> 
         </tr> 
         <tr class="tr1">
            <td class="rldatee daslist"></td>
			<td class="rltitle daslist">
			<input type="submit" value="��¼" style="width:80px;" />
			<input type="reset" value="����" style="width:80px;" />
			<!-- <a href="reg.jsp">
			<input type="button" value="ѧ��ע��" style="width:80px;" />
			</a> -->
			</td> 
         </tr>
         <tr class="tr1">
            <td class="rldatee daslist"></td>
			<td class="rltitle daslist">&nbsp;</td> 
         </tr>  
         <tr class="tr1">
            <td class="rldatee daslist"></td>
			<td class="rltitle daslist">&nbsp;</td> 
         </tr>
      </tbody>
</table> 
</FORM> 
</div>
</div> 
</div>
<%-- <%@ include file="iframe/foot.jsp"%> --%>