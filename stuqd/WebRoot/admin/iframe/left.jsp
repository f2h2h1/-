<%@ page language="java" import="java.util.*" contentType="text/html;charset=gb2312"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<HTML>
<HEAD>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<link rel="stylesheet" href="<%=basePath %>images/css/bootstrap.css" />
<link rel="stylesheet" href="<%=basePath %>images/css/css.css" />
<script type="text/javascript" src="<%=basePath %>images/js/jquery1.9.0.min.js"></script>
<script type="text/javascript" src="<%=basePath %>images/js/bootstrap.min.js"></script>
<script type="text/javascript" src="<%=basePath %>images/js/sdmenu.js"></script>
<script type="text/javascript" src="<%=basePath %>images/js/laydate/laydate.js"></script>
</HEAD>
<%
	String username=(String)session.getAttribute("user");  String sf=(String)session.getAttribute("sf");  
	if(username==null){
		response.sendRedirect(path+"index.jsp");
	}
	else{ 
%>
<body>
<div class="left">
     
<script type="text/javascript">
var myMenu;
window.onload = function() {
	myMenu = new SDMenu("my_menu");
	myMenu.init();
};
</script>

<div id="my_menu" class="sdmenu">
	
	<div class="collapsed">
		<span>������Ϣ����</span>
		<a href="<%=basePath %>admin/system/editpwd.jsp" target="MainFrame">������Ϣ����</a> 
	</div>
	<%if(sf.equals("����Ա")){ %>
	<div class="collapsed">
		<span>���ҹ���</span>
		<a href="<%=basePath %>admin/cw/index.jsp" target="MainFrame">�����б�</a>  
		<a href="<%=basePath %>admin/cw/add.jsp?method=addcw" target="MainFrame">����������Ϣ</a> 
	</div> 
	<div class="collapsed">
		<span>�̵����</span>
		<a href="<%=basePath %>admin/cw/crime.jsp" target="MainFrame">�̵��б�</a> 
		<a href="<%=basePath %>admin/cw/addzx.jsp?method=addzx" target="MainFrame">�����̵���Ϣ</a> 
	</div> 
	<div class="collapsed">
		<span>��Ʒ����</span>
		<a href="<%=basePath %>admin/cw/indexzf.jsp" target="MainFrame">��Ʒ�б�</a> 
		<a href="<%=basePath %>admin/cw/addzf.jsp?method=addzf" target="MainFrame">������Ʒ��Ϣ</a> 
	</div> 
	<%} %>
 	<div class="collapsed">
		<span>ע���˳�ϵͳ</span>
		<a onclick="if (confirm('ȷ��Ҫ�˳���')) return true; else return false;" href="<%=basePath %>AdminServlet?method=adminexit" target="_top" >ע���˳�ϵͳ</a>
	</div> 
</div>
     </div>
     <div class="Switch"></div>
     <script type="text/javascript">
	$(document).ready(function(e) {
    $(".Switch").click(function(){
	$(".left").toggle();
	 
		});
});
</script> 
</body>
<%} %>

</html>
<%-- <div class="collapsed">
		<span>��ҵҪ�����</span>
		<a href="<%=basePath %>admin/byyq/index.jsp" target="MainFrame">��ҵҪ�����</a> 
		<a href="<%=basePath %>admin/byyq/add.jsp?method=addbyyq" target="MainFrame">���ӱ�ҵҪ��</a> 
		 <a href="<%=basePath %>admin/byyq/s.jsp" target="MainFrame">��ҵҪ���ѯ</a>  
	</div> 
	<div class="collapsed">
		<span>ѧ����ҵ����</span>
		<a href="<%=basePath %>admin/sf/index.jsp" target="MainFrame">ѧ����ҵ����</a> 
		<a href="<%=basePath %>admin/sf/add.jsp?method=addsf" target="MainFrame">����ѧ����ҵ</a> 
		 <a href="<%=basePath %>admin/sf/s.jsp" target="MainFrame">ѧ����ҵ��ѯ</a>  
	</div>  --%>