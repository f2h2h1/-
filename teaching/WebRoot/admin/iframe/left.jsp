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
	<%if(sf.equals("ϵͳ����Ա")){ %>  
	<div class="collapsed">
		<span>�����ҹ���Ա</span>
		<a href="<%=basePath %>admin/jys/index.jsp" target="MainFrame">�����ҹ���Ա</a> 
		<a href="<%=basePath %>admin/jys/add.jsp?method=addjys" target="MainFrame">���ӹ���Ա</a> 
		 <a href="<%=basePath %>admin/jys/s.jsp" target="MainFrame">����Ա��ѯ</a>  
	</div> 
	<div class="collapsed">
		<span>��ʦ�û�����</span>
		<a href="<%=basePath %>admin/system/index.jsp" target="MainFrame">��ʦ�û�����</a> 
		<a href="<%=basePath %>admin/system/add.jsp?method=addm" target="MainFrame">���ӽ�ʦ�û�</a> 
		 <a href="<%=basePath %>admin/system/s.jsp" target="MainFrame">��ʦ�û���ѯ</a>  
	</div>
	<div class="collapsed">
		<span>ѧ����Ϣ����</span>
		<a href="<%=basePath %>admin/xs/index.jsp" target="MainFrame">ѧ����Ϣ����</a> 
		<a href="<%=basePath %>admin/xs/add.jsp?method=addxs" target="MainFrame">����ѧ����Ϣ</a>  
		<a href="<%=basePath %>admin/xs/s.jsp" target="MainFrame">ѧ����Ϣ��ѯ</a> 
	</div> 
	
	<%}else if(sf.equals("�����ҹ���Ա")){ %>
	<div class="collapsed">
		<span>������Ϣ����</span>
		<a href="<%=basePath %>admin/jys/index2.jsp" target="MainFrame">������Ϣ����</a>  
	</div>
	<div class="collapsed">
		<span>��ѧ���������</span>
		<a href="<%=basePath %>admin/rws/index.jsp" target="MainFrame">��ѧ���������</a> 
		<a href="<%=basePath %>admin/rws/add.jsp?method=addrws" target="MainFrame">���ӽ�ѧ������</a> 
		 <a href="<%=basePath %>admin/rws/s.jsp" target="MainFrame">��ѧ�������ѯ</a>  
	</div>   
	<div class="collapsed">
		<span>�α���Ϣ����</span>
		<a href="<%=basePath %>admin/kb/index.jsp" target="MainFrame">�α���Ϣ����</a> 
		<a href="<%=basePath %>admin/kb/add.jsp?method=addkb" target="MainFrame">���ӿα���Ϣ</a> 
		 <a href="<%=basePath %>admin/kb/s.jsp" target="MainFrame">�α���Ϣ��ѯ</a>  
	</div> 
	<div class="collapsed">
		<span>�ڿμƻ�����</span>
		<a href="<%=basePath %>admin/sk/index2.jsp" target="MainFrame">�ڿμƻ�����</a>  
		 <a href="<%=basePath %>admin/sk/s2.jsp" target="MainFrame">�ڿμƻ���ѯ</a>  
	</div>
	<div class="collapsed">
		<span>�γ̽������</span>
		<a href="<%=basePath %>admin/jy/index2.jsp" target="MainFrame">�γ̽������</a>  
		 <a href="<%=basePath %>admin/jy/s2.jsp" target="MainFrame">�γ̽����ѯ</a>  
	</div> 
	
	<%}else if(sf.equals("��ʦ")){ %> 
	<div class="collapsed">
		<span>������Ϣ����</span>
		<a href="<%=basePath %>admin/system/index2.jsp" target="MainFrame">������Ϣ����</a>  
	</div>
	<div class="collapsed">
		<span>�α���Ϣ�鿴</span>
		<a href="<%=basePath %>admin/kb/index2.jsp" target="MainFrame">�α���Ϣ�鿴</a>  
		 <a href="<%=basePath %>admin/kb/s2.jsp" target="MainFrame">�α���Ϣ��ѯ</a>  
	</div> 
	<div class="collapsed">
		<span>�ڿμƻ�����</span>
		<a href="<%=basePath %>admin/sk/index.jsp" target="MainFrame">�ڿμƻ�����</a> 
		<a href="<%=basePath %>admin/sk/add.jsp?method=addsk" target="MainFrame">�����ڿμƻ�</a> 
		 <a href="<%=basePath %>admin/sk/s.jsp" target="MainFrame">�ڿμƻ���ѯ</a>  
	</div>
	<div class="collapsed">
		<span>�γ̽������</span>
		<a href="<%=basePath %>admin/jy/index.jsp" target="MainFrame">�γ̽������</a> 
		<a href="<%=basePath %>admin/jy/add.jsp?method=addjy" target="MainFrame">���ӿγ̽���</a> 
		 <a href="<%=basePath %>admin/jy/s.jsp" target="MainFrame">�γ̽����ѯ</a>  
	</div> 
	<div class="collapsed">
		<span>��ҵ��Ϣ����</span>
		<a href="<%=basePath %>admin/zy/index.jsp" target="MainFrame">��ҵ��Ϣ����</a> 
		<a href="<%=basePath %>admin/zy/add.jsp?method=addzy" target="MainFrame">������ҵ��Ϣ</a> 
		 <a href="<%=basePath %>admin/zy/s.jsp" target="MainFrame">��ҵ��Ϣ��ѯ</a>  
	</div> 
	<div class="collapsed">
		<span>�Ͻ���ҵ����</span>
		<a href="<%=basePath %>admin/sc/index2.jsp" target="MainFrame">�Ͻ���ҵ����</a>  
		 <a href="<%=basePath %>admin/sc/s2.jsp" target="MainFrame">�Ͻ���ҵ��ѯ</a>  
	</div>
	<div class="collapsed">
		<span>ʵ���������</span>
		<a href="<%=basePath %>admin/rw/index.jsp" target="MainFrame">ʵ���������</a>  
		<a href="<%=basePath %>admin/rw/add.jsp?method=addrw" target="MainFrame">����ʵ������</a> 
		 <a href="<%=basePath %>admin/rw/s.jsp" target="MainFrame">ʵ�������ѯ</a>  
	</div>
	<div class="collapsed">
		<span>�Ͻ��������</span>
		<a href="<%=basePath %>admin/srw/index2.jsp" target="MainFrame">�Ͻ��������</a>  
		 <a href="<%=basePath %>admin/srw/s2.jsp" target="MainFrame">�Ͻ������ѯ</a>  
	</div> 
	
	
	<%}else if(sf.equals("ѧ��")){ %> 
	<div class="collapsed">
		<span>������Ϣ����</span>
		<a href="<%=basePath %>admin/xs/index2.jsp" target="MainFrame">������Ϣ����</a>  
	</div>
	<div class="collapsed">
		<span>�α���Ϣ�鿴</span>
		<a href="<%=basePath %>admin/kb/index2.jsp" target="MainFrame">�α���Ϣ�鿴</a>  
		 <a href="<%=basePath %>admin/kb/s2.jsp" target="MainFrame">�α���Ϣ��ѯ</a>  
	</div> 
	<div class="collapsed">
		<span>��ҵ��Ϣ�鿴</span>
		<a href="<%=basePath %>admin/zy/index2.jsp" target="MainFrame">��ҵ��Ϣ�鿴</a>  
		 <a href="<%=basePath %>admin/zy/s2.jsp" target="MainFrame">��ҵ��Ϣ��ѯ</a>  
	</div> 
	<div class="collapsed">
		<span>�Ͻ���ҵ����</span>
		<a href="<%=basePath %>admin/sc/index.jsp" target="MainFrame">�Ͻ���ҵ����</a>   
		 <a href="<%=basePath %>admin/sc/s.jsp" target="MainFrame">�Ͻ���ҵ��ѯ</a>  
	</div>
	
	<div class="collapsed">
		<span>ʵ������鿴</span>
		<a href="<%=basePath %>admin/rw/index2.jsp" target="MainFrame">ʵ������鿴</a>  
		 <a href="<%=basePath %>admin/rw/s2.jsp" target="MainFrame">ʵ�������ѯ</a>  
	</div> 
	<div class="collapsed">
		<span>�Ͻ��������</span>
		<a href="<%=basePath %>admin/srw/index.jsp" target="MainFrame">�Ͻ��������</a>   
		 <a href="<%=basePath %>admin/srw/s.jsp" target="MainFrame">�Ͻ������ѯ</a>  
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
