<?php
namespace GPojectPHP\Dao;

use GPojectPHP\Models\Studymaterials;

class StudymaterialsDao extends MainDao
{
	private $objectName = 'GPojectPHP\Models\Studymaterials';

	public function list() : ?array
	{
		$repository = $this->entityManager->getRepository($this->objectName);
		$list = $repository->findAll();

		if ($this->isEmpty($list))
		{
			return null;
		}
		return $list;
	}

	public function add(int $subjetid, string $name, string $savePath, int $teacherid) : ?int
	{
		$timestamp = time();
		$studymaterials = new Studymaterials();
		$studymaterials->setName($name);
		$studymaterials->setTeacherid($teacherid);
		$studymaterials->setSubjectid($subjetid);
		$studymaterials->setPath($savePath);
		$studymaterials->setCreatetime($timestamp);

		$this->entityManager->persist($studymaterials);
		$this->entityManager->flush();

		return $studymaterials->getId();
	}

}
