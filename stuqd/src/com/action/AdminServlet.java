package com.action;
/**
 * ����Ա��½ ���� �޸� ɾ��  
 */
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.List;
import java.util.Random;
import java.util.StringTokenizer;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.bean.ComBean; 
import com.util.Constant;
// import com.util.MD5;

public class AdminServlet extends HttpServlet {

	/**
	 * Constructor of the object.
	 */
	public AdminServlet() {
		super();
	}

	/**
	 * Destruction of the servlet. <br>
	 */
	public void destroy() {
		super.destroy(); // Just puts "destroy" string in log
		// Put your code here
	}

	/**
	 * The doGet method of the servlet. <br>
	 *
	 * This method is called when a form has its tag value method equals to get.
	 * 
	 * @param request the request send by the client to the server
	 * @param response the response send by the server to the client
	 * @throws ServletException if an error occurred
	 * @throws IOException if an error occurred
	 */
	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		doPost(request,response);
	}

	/**
	 * The doPost method of the servlet. <br>
	 *
	 * This method is called when a form has its tag value method equals to post.
	 * 
	 * @param request the request send by the client to the server
	 * @param response the response send by the server to the client
	 * @throws ServletException if an error occurred
	 * @throws IOException if an error occurred
	 */
	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		response.setContentType(Constant.CONTENTTYPE);
		request.setCharacterEncoding(Constant.CHARACTERENCODING);
		String date=new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(Calendar.getInstance().getTime());
		try{
			String method=request.getParameter("method").trim();
			ComBean cBean = new ComBean();
			HttpSession session = request.getSession();   
			if(method.equals("one")){//�û���¼
				String username = request.getParameter("username");
				String password = request.getParameter("password");  
				String sf = request.getParameter("sf");  
				String str ="";
				if(sf.equals("����Ա")){
					str=cBean.getString("select realname from admin where username='"+username+"' and  password='"+password+"'  ");
				}
				if(str==null){
					session.setAttribute("message", "��¼��Ϣ����");
					request.getRequestDispatcher("index.jsp").forward(request, response); 
				}
				else{
					session.setAttribute("user", username);
					session.setAttribute("memberId", str); 
					session.setAttribute("sf", sf); 
					request.getRequestDispatcher("admin/index.jsp").forward(request, response); 
				}  
			}
			else if(method.equals("uppwd")){//�޸�����
				String username=(String)session.getAttribute("user"); 
				String sf=(String)session.getAttribute("sf"); 
				String oldpwd = request.getParameter("oldpwd"); 
				String newpwd = request.getParameter("newpwd"); 
				String table="";
				String user="username";
				if(sf.equals("����Ա")){
				table = "admin";
				}
				String str=cBean.getString("select id from "+table+" where "+user+"='"+username+"' and  password='"+oldpwd+"'");
				if(str==null){
					session.setAttribute("message", "ԭʼ������Ϣ����");
					request.getRequestDispatcher("admin/system/editpwd.jsp").forward(request, response); 
				}
				else{
					int flag=cBean.comUp("update "+table+" set password='"+newpwd+"' where "+user+"='"+username+"'");
					if(flag == Constant.SUCCESS){ 
						session.setAttribute("message", "�����ɹ���");
						request.getRequestDispatcher("admin/system/editpwd.jsp").forward(request, response); 
					}
					else { 
						session.setAttribute("message", "����ʧ�ܣ�");
						request.getRequestDispatcher("admin/system/editpwd.jsp").forward(request, response); 
					}
				}
			}
			else if(method.equals("adminexit")){//�˳���¼
				session.removeAttribute("user");  session.removeAttribute("sf"); 
				request.getRequestDispatcher("index.jsp").forward(request, response); 
			}
			else if(method.equals("addm")){//����ϵͳ�û�
				String username = request.getParameter("username"); 
				String password = request.getParameter("password"); 
				String realname = request.getParameter("realname"); 
				String sex = request.getParameter("sex"); 
				String age = request.getParameter("age"); 
				String address = request.getParameter("address"); 
				String tel = request.getParameter("tel");
				 
						int flag=cBean.comUp("insert into admin(username,password,realname,sex,age,address,tel,addtime) " +
								"values('"+username+"','"+password+"','"+realname+"','"+sex+"','"+age+"','"+address+"','"+tel+"','"+date+"')");
						if(flag == Constant.SUCCESS){ 
							session.setAttribute("message", "�����ɹ���");
							request.getRequestDispatcher("admin/system/index.jsp").forward(request, response); 
						}
						else { 
							session.setAttribute("message", "����ʧ�ܣ�");
							request.getRequestDispatcher("admin/system/index.jsp").forward(request, response); 
						}  
			}
			else if(method.equals("upm")){//�޸�ϵͳ�û�
				String id = request.getParameter("id");
				String password = request.getParameter("password");
				String realname = request.getParameter("realname"); 
				String sex = request.getParameter("sex"); 
				String age = request.getParameter("age"); 
				String address = request.getParameter("address"); 
				String tel = request.getParameter("tel"); 
				int flag=cBean.comUp("update admin set password='"+password+"',realname='"+realname+"',sex='"+sex+"',age='"+age+"'," +
						"address='"+address+"',tel='"+tel+"' where id='"+id+"'");
				if(flag == Constant.SUCCESS){ 
					session.setAttribute("message", "�����ɹ���");
					request.getRequestDispatcher("admin/system/index.jsp").forward(request, response); 
				}
				else { 
					session.setAttribute("message", "����ʧ�ܣ�");
					request.getRequestDispatcher("admin/system/index.jsp").forward(request, response); 
				}
			}
			else if(method.equals("upm2")){//�޸�ϵͳ�û�
				String username=(String)session.getAttribute("user"); 
				String realname = request.getParameter("realname"); 
				String sex = request.getParameter("sex"); 
				String age = request.getParameter("age"); 
				String address = request.getParameter("address"); 
				String tel = request.getParameter("tel"); 
				int flag=cBean.comUp("update admin set realname='"+realname+"',sex='"+sex+"',age='"+age+"'," +
						"address='"+address+"',tel='"+tel+"' where username='"+username+"'");
				if(flag == Constant.SUCCESS){ 
					session.setAttribute("message", "�����ɹ���");
					request.getRequestDispatcher("admin/system/index2.jsp").forward(request, response); 
				}
				else { 
					session.setAttribute("message", "����ʧ�ܣ�");
					request.getRequestDispatcher("admin/system/index2.jsp").forward(request, response); 
				}
			}
			else if(method.equals("delm")){//ɾ��ϵͳ�û�
				String id = request.getParameter("id");  
				int flag=cBean.comUp("delete from admin where id='"+id+"'");
				if(flag == Constant.SUCCESS){ 
					session.setAttribute("message", "�����ɹ���");
					request.getRequestDispatcher("admin/system/index.jsp").forward(request, response); 
				}
				else { 
					session.setAttribute("message", "����ʧ�ܣ�");
					request.getRequestDispatcher("admin/system/index.jsp").forward(request, response); 
				}
			} 
			else{//�޲�������ת������ҳ��
				request.getRequestDispatcher("error.jsp").forward(request, response);
			}
		}catch(Exception e){
			e.printStackTrace();
			request.getRequestDispatcher("error.jsp").forward(request, response);
		}
		
	}

	/**
	 * Initialization of the servlet. <br>
	 *
	 * @throws ServletException if an error occure
	 */
	public void init() throws ServletException {
		// Put your code here
	}

}
