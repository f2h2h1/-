<%@ page language="java" import="java.util.*"  contentType="text/html;charset=gb2312"%>  
<jsp:useBean id="cb" scope="page" class="com.bean.ComBean" />  
<%
  	String path = request.getContextPath();
  	String basePath = request.getScheme() + "://"
  			+ request.getServerName() + ":" + request.getServerPort()
  			+ path + "/";
  	String htmlData = request.getParameter("content1") != null ? request
  			.getParameter("content1")
  			: "";
  %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<link rel="stylesheet" href="<%=basePath%>images/css/bootstrap.css" />
<link rel="stylesheet" href="<%=basePath%>images/css/css.css" />
<script type="text/javascript" src="<%=basePath%>images/js/jquery1.9.0.min.js"></script>
<script type="text/javascript" src="<%=basePath%>images/js/bootstrap.min.js"></script>
<script type="text/javascript" src="<%=basePath%>images/js/sdmenu.js"></script>
<script type="text/javascript" src="<%=basePath%>images/js/laydate/laydate.js"></script>
</head>
<%
	String message = (String) session.getAttribute("message");
	if (message == null) {
		message = "";
	}
	if (!message.trim().equals("")) {
		out.println("<script language='javascript'>");
		out.println("alert('" + message + "');");
		out.println("</script>");
	}
	session.removeAttribute("message");

	String admin = (String) session.getAttribute("user");
	if (admin == null) {
		response.sendRedirect(path + "index.jsp");
	} else {
		String method = request.getParameter("method");
		String id = "";
		String name = "";
		String gclass = "";
		String stock = "";
		
		String password = "";
		if (method.equals("upzf")) {
			id = request.getParameter("id");
			List jlist = cb.get1Com("select * from tb_goods where id='" + id
					+ "'", 4);
			name = jlist.get(1).toString();
			gclass = jlist.get(2).toString();
			stock = jlist.get(3).toString();
		}
%>
<body>
<div class="right_cont">
<div class="title_right"><strong>��Ʒ����</strong></div>  
<div style="width:900px;margin:auto;">
<form action="<%=basePath%>ComServlet" method="post" name="form1">
<table class="table table-bordered"> 
     <tr>
     <input type="hidden" name="method" value="<%=method%>" />
     <input type="hidden" name="id" value="<%=id%>" />
   
     <%if(method.equals("upcw")){ %>
     <td width="40%" align="right" nowrap="nowrap" bgcolor="#f1f1f1">��Ʒ���:</td>
     <td>
     <input type="text" name="id" class="span4" value="<%=id%>" readonly="readonly"/>
     <%}else{ %>
     <%} %>
     </td> 
     </tr> 
     <tr>
     <td width="40%" align="right" nowrap="nowrap" bgcolor="#f1f1f1">��Ʒ���ƣ�</td>
     <td><input type="text" name="name" class="span4" value="<%=name%>" required/></td> 
     </tr> 
     <tr>
     <td width="40%" align="right" nowrap="nowrap" bgcolor="#f1f1f1">��Ʒ���ࣺ</td>
     <td><input type="text" name="gclass" class="span2" value="<%=gclass%>" required/></td> 
     </tr> 

     <tr>
     <td width="40%" align="right" nowrap="nowrap" bgcolor="#f1f1f1">��棺</td>
     <td><input type="text" name="stock" class="span4" value="<%=stock%>" required/></td> 
     </tr> 
     
     <tr>
     	<td class="text-center" colspan="2"><input type="submit" value="ȷ��" class="btn btn-info  " style="width:80px;" /></td>
     </tr>
     </table> 
</form>
   </div>  
 </div>  
</body>
<%
	}
%>