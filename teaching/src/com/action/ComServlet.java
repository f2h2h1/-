package com.action;

import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.bean.ComBean;
import com.util.Constant;

public class ComServlet extends HttpServlet {

	/**
	 * Constructor of the object.
	 */
	public ComServlet() {
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
		HttpSession session = request.getSession();
		ComBean cBean = new ComBean();
		String date=new SimpleDateFormat("yyyy-MM-dd").format(Calendar.getInstance().getTime());
		String date2=new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(Calendar.getInstance().getTime());
		String method = request.getParameter("method");
		
		if(method.equals("delrws")){//ɾ��������
			String id = request.getParameter("id"); 
			int flag = cBean.comUp("delete from rws where id='"+id+"'");
			if(flag == Constant.SUCCESS){ 
				request.setAttribute("message", "�����ɹ���");
				request.getRequestDispatcher("admin/rws/index.jsp").forward(request, response);
			}
			else{
				request.setAttribute("message", "����ʧ�ܣ�");
				request.getRequestDispatcher("admin/rws/index.jsp").forward(request, response);
			}
		} 
		else if(method.equals("delkb")){//ɾ���α�
			String id = request.getParameter("id"); 
			int flag = cBean.comUp("delete from kb where id='"+id+"'");
			if(flag == Constant.SUCCESS){ 
				request.setAttribute("message", "�����ɹ���");
				request.getRequestDispatcher("admin/kb/index.jsp").forward(request, response);
			}
			else{
				request.setAttribute("message", "����ʧ�ܣ�");
				request.getRequestDispatcher("admin/kb/index.jsp").forward(request, response);
			}
		} 
		else if(method.equals("delzy")){//ɾ����ҵ
			String id = request.getParameter("id"); 
			int flag = cBean.comUp("delete from zy where id='"+id+"'");
			if(flag == Constant.SUCCESS){ 
				request.setAttribute("message", "�����ɹ���");
				request.getRequestDispatcher("admin/zy/index.jsp").forward(request, response);
			}
			else{
				request.setAttribute("message", "����ʧ�ܣ�");
				request.getRequestDispatcher("admin/zy/index.jsp").forward(request, response);
			}
		}
		else if(method.equals("delrw")){//ɾ��ʵ������
			String id = request.getParameter("id"); 
			int flag = cBean.comUp("delete from rw where id='"+id+"'");
			if(flag == Constant.SUCCESS){ 
				request.setAttribute("message", "�����ɹ���");
				request.getRequestDispatcher("admin/rw/index.jsp").forward(request, response);
			}
			else{
				request.setAttribute("message", "����ʧ�ܣ�");
				request.getRequestDispatcher("admin/rw/index.jsp").forward(request, response);
			}
		} 
		else if(method.equals("delsk")){//ɾ���ڿμƻ�
			String id = request.getParameter("id"); 
			int flag = cBean.comUp("delete from sk where id='"+id+"'");
			if(flag == Constant.SUCCESS){ 
				request.setAttribute("message", "�����ɹ���");
				request.getRequestDispatcher("admin/sk/index.jsp").forward(request, response);
			}
			else{
				request.setAttribute("message", "����ʧ�ܣ�");
				request.getRequestDispatcher("admin/sk/index.jsp").forward(request, response);
			}
		} 
		else if(method.equals("spsk")){ //�����ڿμƻ� 
			String id=request.getParameter("id");
			String tg = request.getParameter("tg");  
			String yj = request.getParameter("yj"); 
			int flag = cBean.comUp("update sk set tg='"+tg+"' ,yj='"+yj+"' where id='"+id+"'");
			if(flag == Constant.SUCCESS){ 
				request.setAttribute("message", "�����ɹ���");
				request.getRequestDispatcher("admin/sk/index2.jsp").forward(request, response);
			}
			else{
				request.setAttribute("message", "����ʧ�ܣ�");
				request.getRequestDispatcher("admin/sk/index2.jsp").forward(request, response);
			}  
		} 
		else if(method.equals("delsk2")){//ɾ���ڿμƻ�
			String id = request.getParameter("id"); 
			int flag = cBean.comUp("delete from sk where id='"+id+"'");
			if(flag == Constant.SUCCESS){ 
				request.setAttribute("message", "�����ɹ���");
				request.getRequestDispatcher("admin/sk/index2.jsp").forward(request, response);
			}
			else{
				request.setAttribute("message", "����ʧ�ܣ�");
				request.getRequestDispatcher("admin/sk/index2.jsp").forward(request, response);
			}
		} 
		else if(method.equals("deljy")){//ɾ���γ̽���
			String id = request.getParameter("id"); 
			int flag = cBean.comUp("delete from jy where id='"+id+"'");
			if(flag == Constant.SUCCESS){ 
				request.setAttribute("message", "�����ɹ���");
				request.getRequestDispatcher("admin/jy/index.jsp").forward(request, response);
			}
			else{
				request.setAttribute("message", "����ʧ�ܣ�");
				request.getRequestDispatcher("admin/jy/index.jsp").forward(request, response);
			}
		} 
		else if(method.equals("deljy2")){//ɾ���γ̽���
			String id = request.getParameter("id"); 
			int flag = cBean.comUp("delete from jy where id='"+id+"'");
			if(flag == Constant.SUCCESS){ 
				request.setAttribute("message", "�����ɹ���");
				request.getRequestDispatcher("admin/jy/index2.jsp").forward(request, response);
			}
			else{
				request.setAttribute("message", "����ʧ�ܣ�");
				request.getRequestDispatcher("admin/jy/index2.jsp").forward(request, response);
			}
		} 
		else if(method.equals("spjy")){ //�����γ̽��� 
			String id=request.getParameter("id");
			String tg = request.getParameter("tg");  
			String yj = request.getParameter("yj"); 
			int flag = cBean.comUp("update jy set tg='"+tg+"' ,yj='"+yj+"' where id='"+id+"'");
			if(flag == Constant.SUCCESS){ 
				request.setAttribute("message", "�����ɹ���");
				request.getRequestDispatcher("admin/jy/index2.jsp").forward(request, response);
			}
			else{
				request.setAttribute("message", "����ʧ�ܣ�");
				request.getRequestDispatcher("admin/jy/index2.jsp").forward(request, response);
			}  
		} 
		
		else if(method.equals("delsc")){//ɾ���Ͻ���ҵ
			String id = request.getParameter("id"); 
			int flag = cBean.comUp("delete from sc where id='"+id+"'");
			if(flag == Constant.SUCCESS){ 
				request.setAttribute("message", "�����ɹ���");
				request.getRequestDispatcher("admin/sc/index.jsp").forward(request, response);
			}
			else{
				request.setAttribute("message", "����ʧ�ܣ�");
				request.getRequestDispatcher("admin/sc/index.jsp").forward(request, response);
			}
		} 
		else if(method.equals("spsc")){ //�����Ͻ���ҵ 
			String id=request.getParameter("id");
			String pf = request.getParameter("pf");  
			String py = request.getParameter("py"); 
			int flag = cBean.comUp("update sc set pf='"+pf+"' ,py='"+py+"' where id='"+id+"'");
			if(flag == Constant.SUCCESS){ 
				request.setAttribute("message", "�����ɹ���");
				request.getRequestDispatcher("admin/sc/index2.jsp").forward(request, response);
			}
			else{
				request.setAttribute("message", "����ʧ�ܣ�");
				request.getRequestDispatcher("admin/sc/index2.jsp").forward(request, response);
			}  
		} 
		else if(method.equals("delsc2")){//ɾ���Ͻ���ҵ
			String id = request.getParameter("id"); 
			int flag = cBean.comUp("delete from sc where id='"+id+"'");
			if(flag == Constant.SUCCESS){ 
				request.setAttribute("message", "�����ɹ���");
				request.getRequestDispatcher("admin/sc/index2.jsp").forward(request, response);
			}
			else{
				request.setAttribute("message", "����ʧ�ܣ�");
				request.getRequestDispatcher("admin/sc/index2.jsp").forward(request, response);
			}
		} 
		
		
		
		else if(method.equals("delsrw")){//ɾ���Ͻ�����
			String id = request.getParameter("id"); 
			int flag = cBean.comUp("delete from srw where id='"+id+"'");
			if(flag == Constant.SUCCESS){ 
				request.setAttribute("message", "�����ɹ���");
				request.getRequestDispatcher("admin/srw/index.jsp").forward(request, response);
			}
			else{
				request.setAttribute("message", "����ʧ�ܣ�");
				request.getRequestDispatcher("admin/srw/index.jsp").forward(request, response);
			}
		} 
		else if(method.equals("spsrw")){ //�����Ͻ����� 
			String id=request.getParameter("id");
			String pf = request.getParameter("pf");  
			String py = request.getParameter("py"); 
			int flag = cBean.comUp("update srw set pf='"+pf+"' ,py='"+py+"' where id='"+id+"'");
			if(flag == Constant.SUCCESS){ 
				request.setAttribute("message", "�����ɹ���");
				request.getRequestDispatcher("admin/srw/index2.jsp").forward(request, response);
			}
			else{
				request.setAttribute("message", "����ʧ�ܣ�");
				request.getRequestDispatcher("admin/srw/index2.jsp").forward(request, response);
			}  
		} 
		else if(method.equals("delsrw2")){//ɾ���Ͻ�����
			String id = request.getParameter("id"); 
			int flag = cBean.comUp("delete from srw where id='"+id+"'");
			if(flag == Constant.SUCCESS){ 
				request.setAttribute("message", "�����ɹ���");
				request.getRequestDispatcher("admin/srw/index2.jsp").forward(request, response);
			}
			else{
				request.setAttribute("message", "����ʧ�ܣ�");
				request.getRequestDispatcher("admin/srw/index2.jsp").forward(request, response);
			}
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
